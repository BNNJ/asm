/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_to_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clonger <clonger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 14:23:33 by clonger           #+#    #+#             */
/*   Updated: 2018/01/16 14:40:56 by clonger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_tab_to_str(char **tab, char *space)
{
	char	*str;
	int		length;
	int		y;

	length = 0;
	y = 0;
	if (!tab)
		return (NULL);
	while (tab[y])
		length += ft_strlen(tab[y++]);
	if (!space)
		y = 0;
	if (!(str = ft_strnew(length + ft_strlen(space) * (y - 1))))
		return (NULL);
	y = 0;
	while (tab[y])
	{
		str = ft_strjoinfree(str, tab[y], 1);
		if (space && tab[y + 1])
			str = ft_strjoinfree(str, space, 1);
		y++;
	}
	return (str);
}
