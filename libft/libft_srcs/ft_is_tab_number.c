/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_tab_number.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clonger <clonger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 22:33:42 by clonger           #+#    #+#             */
/*   Updated: 2019/04/01 22:53:19 by clonger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_is_tab_number(char **tab)
{
	int		y;

	y = 0;
	if (!tab || !*tab)
		return (0);
	while (tab[y])
		if (!ft_only_number(tab[y++]))
			return (0);
	return (1);
}
