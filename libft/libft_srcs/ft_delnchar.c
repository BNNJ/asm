/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delnchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clonger <clonger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 14:57:24 by clonger           #+#    #+#             */
/*   Updated: 2018/01/16 12:31:43 by clonger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_delnchar(const char *s, int c, int start, int length)
{
	char	*str;
	int		n;
	int		i;

	i = start;
	n = 0;
	if (!s || !c)
		return (NULL);
	if (!(ft_strchr(s, c)))
		return ((char *)s);
	while (s[i] && i < length)
		if (s[i++] == c)
			n++;
	if (!(str = ft_strnew(ft_strlen(s) - n)))
		return (NULL);
	if (start != 0)
		str = ft_strsub(s, 0, ft_strlen(s) - (ft_strlen(s) - start));
	while (s[start] && length--)
	{
		if (s[start++] != c)
			str[ft_strlen(str)] = s[start - 1];
	}
	if (s[start])
		str = ft_strncat(str, &s[start], ft_strlen(s) - start);
	return (str);
}
