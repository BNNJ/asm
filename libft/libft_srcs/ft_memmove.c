/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clonger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:42:56 by clonger           #+#    #+#             */
/*   Updated: 2017/11/08 17:42:56 by clonger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	char		*str_dst;
	const char	*str_src;

	i = 0;
	str_dst = (char *)dst;
	str_src = (const char *)src;
	if (str_dst < str_src)
	{
		while (i < len)
		{
			str_dst[i] = str_src[i];
			i++;
		}
	}
	else
	{
		while (len > 0)
		{
			len--;
			str_dst[len] = str_src[len];
		}
	}
	return (dst);
}
