/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrsub.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clonger <clonger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/31 13:35:07 by clonger           #+#    #+#             */
/*   Updated: 2017/12/31 13:53:40 by clonger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t			*ft_wstrsub(wchar_t const *ws, unsigned int start, size_t len)
{
	wchar_t		*wstr;
	size_t		wi;
	size_t		i;

	if (!(wstr = (wchar_t *)malloc(sizeof(wchar_t) * len + 1)))
		return (NULL);
	wi = 0;
	i = 0;
	if (!ws)
		return (NULL);
	else
	{
		wi += ft_wchrlen(ws[start]);
		while (ws[start] && wi <= len)
		{
			wstr[i] = ws[start];
			wi += ft_wchrlen(wstr[i]);
			i++;
			start++;
		}
		wstr[i] = '\0';
	}
	return (wstr);
}
