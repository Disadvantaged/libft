/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgolear <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 16:18:07 by dgolear           #+#    #+#             */
/*   Updated: 2017/01/07 16:35:10 by dgolear          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>
#include <limits.h>
#include "ft_printf.h"

char	g_base[] = "0123456789abcdef";

void	print_addr(void *p)
{
	char		*s;
	long		i;
	int			len;
	int			copy;

	len = 0;
	i = (long)p;
	copy = i;
	while (copy > 0)
	{
		len++;
		copy /= 16;
	}
	len = len + 6;
	s = malloc(len + 1);
	s[len--] = '\0';
	s[0] = '0';
	s[1] = 'x';
	while (i > 0)
	{
		s[len] = g_base[i % 16];
		i /= 16;
		len--;
	}
	printf("%s\n", s);
}

int		main(void)
{
	char	c = 'h';

	printf("%p\n", c);
	print_addr(&c);
}
