/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedriclonger <cedriclonger@student.42.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 16:26:10 by clonger           #+#    #+#             */
/*   Updated: 2018/02/26 20:54:27 by cedriclonger     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*mall;

	if ((mall = (char *)malloc(sizeof(char) * size)) == NULL)
		return (NULL);
	while (size-- > 0)
		mall[size] = 0;
	return ((void *)mall);
}
