/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgolear <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 15:32:15 by dgolear           #+#    #+#             */
/*   Updated: 2017/01/14 15:32:48 by dgolear          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_sign(intmax_t val, t_param *params)
{
	if (val < 0)
		ft_putchar('-');
	if (val >= 0 && params->flags[0].sign)
		ft_putchar('+');
	if (val >= 0 && params->flags[5].sign)
		ft_putchar(' ');
	if (val < 0
		|| (val >= 0 && (params->flags[0].sign || params->flags[5].sign)))
		return (1);
	return (0);
}
