/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdelnchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clonger <clonger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 12:25:13 by clonger           #+#    #+#             */
/*   Updated: 2018/02/02 12:33:12 by clonger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_vdelnchar(char *s, int c, int start, int length)
{
	char	tmp;
	char	tmp2;
	int		i;

	i = start;
	if (!s || !c || !(ft_strchr(s, c)))
		return ;
	(length > (int)ft_strlen(s)) ? length = ft_strlen(s) : length;
	while (length--)
	{
		i = start;
		if (s[start] == c)
		{
			while (i < (int)ft_strlen(s))
			{
				tmp = s[i];
				tmp2 = s[i + 1];
				s[i++] = tmp2;
				s[i] = tmp;
			}
			s[i] = '\0';
		}
		else
			start++;
	}
}
