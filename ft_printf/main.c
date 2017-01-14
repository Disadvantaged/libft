/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgolear <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 16:18:07 by dgolear           #+#    #+#             */
/*   Updated: 2017/01/14 17:00:43 by dgolear          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>
#include <limits.h>
#include "ft_printf.h"

char	g_base[] = "0123456789abcdef";

int		main(void)
{
	char	*s;
	int		i1;
	int		i2;

	printf("%#O\n", 0);
	ft_printf("%#o\n", 0);
	printf("%*d\n", -5, 42);
	ft_printf("%*d\n", -5, 42);
}
