/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isblank.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgolear <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/23 18:37:45 by dgolear           #+#    #+#             */
/*   Updated: 2016/10/23 18:40:37 by dgolear          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isblank(int ch)
{
	if (ch == ' ' || ch == '\t')
		return (1);
	else
		return (0);
}
