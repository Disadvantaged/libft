/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgolear <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 10:28:32 by dgolear           #+#    #+#             */
/*   Updated: 2017/01/23 16:42:30 by dgolear          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoa(intmax_t n)
{
	char	*s;
	int		i;

	i = ft_nbrlen(n);
	if (n < 0)
		i++;
	if ((s = ft_strnew(i + 1)) == NULL)
		return (NULL);
	if (n == (intmax_t)-9223372036854775808U)
		return (ft_strcpy(s, "-9223372036854775808"));
	i--;
	if (n < 0)
	{
		s[0] = '-';
		n = -n;
	}
	if (n == 0)
		s[0] = '0';
	while (n > 0)
	{
		s[i] = '0' + (n % 10);
		n = n / 10;
		i--;
	}
	return (s);
}
