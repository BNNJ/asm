/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clonger <clonger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 16:28:33 by clonger           #+#    #+#             */
/*   Updated: 2018/02/15 13:19:41 by clonger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_counttab(const char **tab)
{
	size_t		count;

	count = 0;
	while (tab[count])
		count++;
	return (count);
}

char			**ft_tabdup(const char **tab)
{
	size_t		length;
	size_t		tablen;
	char		**ret;
	int			y;

	y = 0;
	if (!tab)
		return (NULL);
	tablen = ft_counttab(tab);
	if (!(ret = (char **)malloc(sizeof(char *) * (tablen + 1))))
		return (NULL);
	while (tab[y])
	{
		length = ft_strlen(tab[y]);
		ret[y] = ft_strsub(tab[y], 0, length);
		y++;
	}
	ret[y] = NULL;
	return (ret);
}
