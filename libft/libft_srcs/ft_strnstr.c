/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clonger <clonger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 14:12:05 by clonger           #+#    #+#             */
/*   Updated: 2017/12/16 12:37:02 by clonger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	mem_i;
	size_t	length;

	length = ft_strlen(s2);
	i = 0;
	j = 0;
	mem_i = 0;
	if (!s2 || !(*s2))
		return ((char *)s1);
	while (s1[i] && i < len)
	{
		mem_i = i;
		while (s2[j] == s1[i + j] && mem_i < len)
		{
			if (j == length - 1)
				return ((char *)s1 + i);
			j++;
			mem_i++;
		}
		j = 0;
		i++;
	}
	return (NULL);
}
