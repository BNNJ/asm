/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clonger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:34:13 by clonger           #+#    #+#             */
/*   Updated: 2017/11/08 17:34:13 by clonger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char*)dst;
	while (i < n)
	{
		*(char*)str = *(char*)src;
		str++;
		src++;
		i++;
	}
	return (dst);
}
