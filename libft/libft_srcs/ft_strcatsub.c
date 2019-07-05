/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcatsub.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clonger <clonger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 02:22:04 by clonger           #+#    #+#             */
/*   Updated: 2018/01/16 12:31:39 by clonger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_check(char *s2, char rep, int i)
{
	int			count;

	count = 0;
	while (s2[i])
	{
		if (s2[i] == rep)
			count++;
		if (s2[i] != rep)
			i = ft_strlen(s2);
		else
			i++;
	}
	return (count);
}

static void		ft_preparestr(char *str, char *s1, char *s2, int i)
{
	int			j;

	j = 0;
	if (i == 0)
		str = ft_strcpy(str, s1);
	else
	{
		while (j < i)
		{
			str[j] = s2[j];
			j++;
		}
		str = ft_strcat(str, s1);
	}
}

char			*ft_strcatsub(char *s1, char *s2, char rep, int i)
{
	char		*str;
	int			s1length;
	int			j;
	int			count;

	s1length = (int)ft_strlen(s1);
	count = 0;
	j = s1length + i;
	if (!s1 || !s2)
		return (NULL);
	if (!rep)
		return (s2);
	count = ft_check(s2, rep, i);
	if (count < s1length)
		return (s2);
	if (!(str = ft_strnew(s1length + (ft_strlen(s2) - s1length))))
		return (NULL);
	ft_preparestr(str, s1, s2, i);
	while (s2[i])
	{
		str[j++] = s2[i + s1length];
		i++;
	}
	str[j] = '\0';
	return (str);
}
