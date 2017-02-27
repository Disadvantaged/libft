/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgolear <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/15 08:27:36 by dgolear           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2017/02/05 12:49:50 by dgolear          ###   ########.fr       */
=======
/*   Updated: 2017/02/22 16:01:25 by dgolear          ###   ########.fr       */
>>>>>>> 0930dd9db40daf54b2ea4bb77e9c219d3560b74b
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const void *a, const void *b)
{
	size_t		i;
	char		*s1;
	char		*s2;

	s1 = (char *)a;
	s2 = (char *)b;
	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
