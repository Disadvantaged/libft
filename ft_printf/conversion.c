/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgolear <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 15:17:53 by dgolear           #+#    #+#             */
/*   Updated: 2017/01/13 18:53:55 by dgolear          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_conv	g_conv[] =
{
	{'d', &print_int},
	{'i', &print_int},
	{'%', &print_percent},
	{'n', &print_len},
	{'s', &print_string},
	{'S', &print_string},
	{'c', &print_char},
	{'C', &print_char},
	{'p', &print_adress}
};

int		g_num = 9;

int	print_percent(t_param *params, va_list ap, char letter)
{
	int		width;

	if (ap || letter)
		;
	width = params->width;
	if (params->flags[1].sign)
		ft_putchar('%');
	while (width > 1)
	{
		if (params->flags[2].sign)
			ft_putchar('0');
		else
			ft_putchar(' ');
		width--;
	}
	if (!params->flags[1].sign)
		ft_putchar('%');
	return (params->width);
}

int	conversion(const char *format, int *pos, t_param *params, va_list ap)
{
	int		i;
	int		printed;

	i = 0;
	while (i < g_num)
	{
		if (format[*pos] == g_conv[i].spec)
		{
			(*pos)++;
			printed = g_conv[i].fun(params, ap, g_conv[i].spec);
			return (printed);
		}
		i++;
	}
	return (0);
}
