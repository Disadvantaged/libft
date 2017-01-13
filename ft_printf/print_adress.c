/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_address.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgolear <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 18:21:55 by dgolear           #+#    #+#             */
/*   Updated: 2017/01/13 18:57:11 by dgolear          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char g_base[] = "0123456789abcdef";

static char	*print_addr(void *p)
{
	char		*s;
	long		i;
	int			len;
	long		copy;

	len = 0;
	i = (long)p;
	copy = i;
	while (copy > 0)
	{
		len++;
		copy /= 16;
	}
	s = malloc(len + 1);
	s[len--] = '\0';
	while (i > 0)
	{
		s[len] = g_base[i % 16];
		i /= 16;
		len--;
	}
	return (s);
}

static void	print_width(t_param *params, char *adress)
{
	int		width;

	width = params->width;
	if (params->flags[1].sign)
	{
		ft_putstr("0x");
		ft_putstr(adress);
		while (width > 14)
		{
			ft_putchar(' ');
			width--;
		}
	}
	else
	{
		if (params->flags[2].sign)
			ft_putstr("0x");
		while (width > 14)
		{
			if (params->flags[2].sign)
				ft_putchar('0');
			else
				ft_putchar(' ');
			width--;
		}
		if (!params->flags[2].sign)
			ft_putstr("0x");
		ft_putstr(adress);
	}
}

int			print_adress(t_param *params, va_list ap, char letter)
{
	void	*addr;
	char	*adress;

	if (letter)
		;
	addr = va_arg(ap, void *);
	adress = print_addr(addr);
	if (params->width <= 14)
		params->width = 14;
	if (params->width > 14)
	{
		print_width(params, adress);
	}
	else
	{
		ft_putstr("0x");
		ft_putstr(adress);
	}
	free(adress);
	return (params->width);
}
