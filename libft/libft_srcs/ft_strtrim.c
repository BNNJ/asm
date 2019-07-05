/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clonger <clonger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 18:05:39 by clonger           #+#    #+#             */
/*   Updated: 2018/02/06 15:46:21 by clonger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	size_t	i;
	size_t	length;

	i = 0;
	if (!s)
		return (NULL);
	length = ft_strlen(s) - 1;
	if (ft_isspace(s[i]) && s[i])
	{
		while (ft_isspace(s[i]))
			i++;
	}
	if (ft_isspace(s[length]) && length > 0)
	{
		while (ft_isspace(s[length]) && length > 0)
			length--;
	}
	if (!s[i])
		str = ft_strdup("");
	else
		str = ft_strsub(s, i, length + 1 - i);
	return (str);
}
