/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addnwchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clonger <clonger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 18:09:28 by clonger           #+#    #+#             */
/*   Updated: 2018/02/01 13:30:45 by clonger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t		*ft_addnwchar(wchar_t *str, int start, wchar_t c, int length)
{
	wchar_t		*ret;
	int			j;
	int			len;

	j = 0;
	len = ft_wstrlen(str, "strlen");
	if (!(ret = ft_memalloc(sizeof(wchar_t) * (len + length + 1))))
		return (NULL);
	if (start > 0)
	{
		while (j < start)
		{
			ret[j] = str[j];
			j++;
		}
	}
	while (length-- > 0)
		ret[j++] = c;
	while (str[start])
		ret[j++] = str[start++];
	ret[j] = '\0';
	free(str);
	return (ret);
}
