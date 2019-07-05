/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clonger <clonger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 11:58:07 by clonger           #+#    #+#             */
/*   Updated: 2017/12/20 14:53:16 by clonger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t			*ft_wstrdup(const wchar_t *ws)
{
	int			length;
	int			i;
	wchar_t		*wstr;

	length = ft_wstrlen((wchar_t *)ws, "strlen");
	i = 0;
	if (!ws)
		return (NULL);
	if (!(wstr = ft_memalloc(sizeof(wchar_t) * length + 1)))
		return (NULL);
	while (ws[i])
	{
		wstr[i] = ws[i];
		i++;
	}
	wstr[i] = '\0';
	return (wstr);
}
