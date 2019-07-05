/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 12:58:16 by clonger           #+#    #+#             */
/*   Updated: 2017/11/29 02:41:20 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	a;
	int		length;

	a = (char)c;
	length = ft_strlen(s);
	while (length > 0)
	{
		if (s[length] == a)
			return ((char*)s + length);
		else
			length--;
	}
	if (s[length] == a)
		return ((char*)s + length);
	return (NULL);
}
