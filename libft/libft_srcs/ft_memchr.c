/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clonger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:56:34 by clonger           #+#    #+#             */
/*   Updated: 2017/11/08 17:56:34 by clonger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	a;
	unsigned char	*str;

	a = (unsigned char)c;
	str = (unsigned char*)s;
	i = 0;
	while (i < n)
	{
		if (str[i] == a)
			return (str + i);
		else
			i++;
	}
	return (NULL);
}
