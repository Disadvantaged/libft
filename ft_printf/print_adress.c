/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_address.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgolear <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 18:21:55 by dgolear           #+#    #+#             */
/*   Updated: 2017/01/13 19:24:39 by dgolear          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char g_base[] = "0123456789abcdef";

static char	*print_addr(void *p)
{
	char			*s;
	unsigned long	i;
	int				len;
	unsigned long	copy;

	len = 0;
	i = (unsigned long)p;
	copy = i;
	while (copy > 0)
	{
		len++;
		copy /= 16;
	}
	if (len == 0)
		return (ft_strdup("0"));
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
		while (width > (int)ft_strlen(adress) + 2)
		{
			ft_putchar(' ');
			width--;
		}
	else
	{
		if (params->flags[2].sign)
			ft_putstr("0x");
		while (width > (int)ft_strlen(adress) + 2)
		{
			if (params->flags[2].sign)
				ft_putchar('0');
			else
				ft_putchar(' ');
			width--;
		}
		if (!params->flags[2].sign)
			ft_putstr("0x");
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
	if (params->width <= (int)ft_strlen(adress) + 2)
	{
		params->width = ft_strlen(adress) + 2;
		ft_putstr("0x");
		ft_putstr(adress);
	}
	else if (params->flags[1].sign)
	{
		ft_printf("0x%s", adress);
		print_width(params, adress);
	}
	else
	{
		print_width(params, adress);
		ft_putstr(adress);
	}
	free(adress);
	return (params->width);
}
