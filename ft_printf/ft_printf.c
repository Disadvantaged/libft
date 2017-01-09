/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgolear <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 16:00:34 by dgolear           #+#    #+#             */
/*   Updated: 2017/01/07 13:31:52 by dgolear          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		g_len = 0;

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	int			i;

	i = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] != '%')
		{
			ft_putchar(format[i]);
			g_len++;
			i++;
		}
		else if (!format[++i] || check(format, &i, ap) < 0)
			return (-1);
	}
	va_end(ap);
	return (g_len);
}

int		check(const char *format, int *pos, va_list ap)
{
	int			length;
	t_param		*params;

	length = 0;
	if ((params = (t_param*)ft_memalloc(sizeof(t_param))) == NULL
		|| (params->flags = check_flags(format, pos)) == NULL)
		return (-1);
	params->width = check_width(format, pos, ap);
	params->precision = check_precision(format, pos, ap);
	params->mod = check_length(format, pos);
	if ((length = conversion(format, pos, params, ap)) == -1)
		return (-1);
	free(params->flags);
	free(params);
	g_len += length;
	return (0);
}

int		print_len(t_param *params, va_list ap, char letter)
{
	int		*pointer;

	if (params || letter)
		;
	pointer = va_arg(ap, int *);
	*pointer = g_len;
	return (0);
}
