/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgolear <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 15:30:50 by dgolear           #+#    #+#             */
/*   Updated: 2017/01/03 15:33:10 by dgolear          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_size(t_param *params, va_list ap)
{
	intmax_t val;

	val = va_arg(ap, intmax_t);
	if (params->mod == hh)
		val = (signed char)val;
	else if (params->mod == h)
		val = (short)val;
	else if (params->mod == l)
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
