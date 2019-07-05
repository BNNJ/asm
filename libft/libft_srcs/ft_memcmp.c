/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clonger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 18:52:06 by clonger           #+#    #+#             */
/*   Updated: 2017/11/08 18:52:07 by clonger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	char	*str1;
	char	*str2;

	i = 0;
	str1 = (char*)s1;
	str2 = (char*)s2;
	if (n == 0)
		return (0);
	else
	{
		while (str1[i] == str2[i] && i < n - 1)
			i++;
	}
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}
