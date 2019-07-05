/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clonger <clonger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 18:57:39 by clonger           #+#    #+#             */
/*   Updated: 2017/12/20 14:39:49 by clonger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_wstrlen(wchar_t *wstr, const char *option)
{
	int			count;
	int			i;

	count = 0;
	i = 0;
	if (!wstr || !option)
		return (0);
	if (ft_strequ(option, "strlen"))
	{
		while (wstr[count])
			count++;
	}
	else if (ft_strequ(option, "wstrlen"))
	{
		while (wstr[i])
			count += ft_wchrlen(wstr[i++]);
	}
	else
		return (0);
	return (count);
}
