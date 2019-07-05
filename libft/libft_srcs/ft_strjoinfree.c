/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clonger <clonger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 15:01:57 by clonger           #+#    #+#             */
/*   Updated: 2018/01/16 12:42:16 by clonger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_free(char *s1, char *s2, int option)
{
	if (option == 0)
		return ;
	if (option == 1 || option == 3)
		ft_strdel(&s1);
	if (option == 2 || option == 3)
		ft_strdel(&s2);
}

char			*ft_strjoinfree(char const *s1, char const *s2, int option)
{
	char	*str;
	size_t	total_length;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	total_length = ft_strlen(s1) + ft_strlen(s2);
	if (!(str = ft_strnew(total_length)))
		return (NULL);
	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	while (i < total_length)
	{
		while (s1[j])
			str[i++] = s1[j++];
		j = 0;
		while (s2[j])
			str[i++] = s2[j++];
	}
	str[i] = '\0';
	ft_free((char *)s1, (char *)s2, option);
	return (str);
}
