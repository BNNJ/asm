/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clonger <clonger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 00:44:27 by clonger           #+#    #+#             */
/*   Updated: 2019/05/09 01:49:26 by clonger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_tabrev(char **tab)
{
	char		*tmp;
	size_t		length;
	int			i;

	i = 0;
	tmp = NULL;
	length = ft_tablen((const char **)tab) - 1;
	while (i < (int)length)
	{
		tmp = tab[i];
		tab[i] = tab[length];
		tab[length] = tmp;
		length--;
		i++;
	}
}
