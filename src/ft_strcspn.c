/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgolear <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 14:51:51 by dgolear           #+#    #+#             */
/*   Updated: 2017/03/06 14:52:46 by dgolear          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strcspn(const char *s1, const char *s2)
{
	int		i;

	i = 0;
	while (s1[i] && ft_strchr(s2, s1[i]) == NULL)
		i++;
	return (i);
}