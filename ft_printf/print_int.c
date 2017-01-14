/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgolear <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 16:48:26 by dgolear           #+#    #+#             */
/*   Updated: 2017/01/14 15:42:30 by dgolear          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_size(t_param *params, va_list ap, char letter)
{
	intmax_t val;

	val = va_arg(ap, intmax_t);
	if (params->mod == hh)
		val = (signed char)val;
	else if (params->mod == h)
		val = (short)val;
	else if (params->mod == l || letter == 'D')
		val = (long)val;
	else if (params->mod == ll)
		val = (long long)val;
	else if (params->mod == j)
		val = (intmax_t)val;
	else if (params->mod == z)
		val = (size_t)val;
	else
		val = (int)val;
	return (val);
}

static int	print_width(intmax_t val, t_param *params)
{
	int		len;
	int		printed;

	printed = 0;
	if (val < 0
		|| (val >= 0 && (params->flags[0].sign || params->flags[5].sign)))
		params->width--;
	len = ft_nbrlen(val);
	if (params->flags[2].sign && !params->flags[1].sign)
		printed += print_sign(val, params);
	while (params->width > len && params->width > params->precision)
	{
		if (params->flags[2].sign)
			ft_putchar('0');
		else
			ft_putchar(' ');
		printed++;
		params->width--;
	}
	if (!params->flags[2].sign && !params->flags[1].sign)
		printed += print_sign(val, params);
	return (printed);
}

static int	print_precision(intmax_t val, t_param *params)
{
	int		printed;
	int		len;
	int		precision;

	precision = params->precision;
	len = ft_nbrlen(val);
	printed = 0;
	if (val < 0 && params->flags[1].sign)
		printed += print_sign(val, params);
	while (precision > len)
	{
		ft_putchar('0');
		printed++;
		precision--;
	}
	return (printed);
}

static int	print_value(intmax_t val, t_param *params)
{
	char		*s;
	int			printed;

	printed = 0;
	if (val < 0)
	{
		if (val == INTMAX_MIN)
			s = ft_strdup("9223372036854775807");
		else
			s = ft_itoa(-val);
	}
	else
		s = ft_itoa(val);
	while (s[printed])
	{
		ft_putchar(s[printed++]);
		if (params->flags[4].sign && printed % 3 == 0)
			ft_putchar('\'');
	}
	if (params->flags[4].sign)
		printed += printed / 4;
	ft_strdel(&s);
	return (printed);
}

int			print_int(t_param *params, va_list ap, char letter)
{
	int			printed;
	intmax_t	val;

	printed = 0;
	val = get_size(params, ap, letter);
	if (val == 0 && params->precision == 0)
		return (0);
	if (params->flags[1].sign)
	{
		printed += print_precision(val, params);
		printed += print_value(val, params);
		printed += print_width(val, params);
	}
	else
	{
		printed += print_width(val, params);
		printed += print_precision(val, params);
		printed += print_value(val, params);
	}
	return (printed);
}
