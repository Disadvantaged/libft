/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgolear <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 16:18:07 by dgolear           #+#    #+#             */
/*   Updated: 2017/01/13 19:23:14 by dgolear          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>
#include <limits.h>
#include "ft_printf.h"

char	g_base[] = "0123456789abcdef";

void	print_addr(void *p)
{
}

int		main(void)
{
	char	c = 'h';
	int		i1;
	int		i2;

	i1 = ft_printf("%5p\n", (void *)-0);
	i2 = printf("%5p\n", (void *)-0);
	printf("%d %d\n", i1, i2);
}
