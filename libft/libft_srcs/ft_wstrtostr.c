/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrtostr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clonger <clonger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 15:58:38 by clonger           #+#    #+#             */
/*   Updated: 2018/01/15 16:11:05 by clonger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_wstrtostr(wchar_t *wstr)
{
	char	*str;
	int		i;

	i = 0;
	if (!wstr)
		return (NULL);
	while (wstr[i])
		if (ft_wchrlen(wstr[i++]) != 1)
			return (NULL);
	i = -1;
	if (!(str = ft_strnew(ft_wstrlen(wstr, "strlen"))))
		return (NULL);
	while (wstr[++i])
		str[i] = wstr[i];
	str[i] = '\0';
	return (str);
}
