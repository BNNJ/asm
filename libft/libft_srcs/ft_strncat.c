/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clonger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 11:16:24 by clonger           #+#    #+#             */
/*   Updated: 2017/11/08 11:16:26 by clonger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	length;

	i = 0;
	length = ft_strlen(s1);
	while (s2[i] != '\0' && i < n)
		s1[length++] = s2[i++];
	s1[length] = '\0';
	return (s1);
}
