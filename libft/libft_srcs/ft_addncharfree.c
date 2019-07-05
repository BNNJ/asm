/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addncharfree.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clonger <clonger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 14:47:19 by clonger           #+#    #+#             */
/*   Updated: 2019/05/07 14:12:00 by clonger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_addncharfree(char *source, char c, int length, double option)
{
	int		i;
	int		start;
	char	*str;

	i = 0;
	start = option;
	option = ((option - start));
	option = option / 0.1;
	if (!source)
		return (NULL);
	if (!c)
		return (source);
	if (!(str = ft_strnew(ft_strlen(source) + length)))
		return (NULL);
	while (i != start)
	{
		str[i] = source[i];
		i++;
	}
	while (length--)
		str[i++] = c;
	while (source[start])
		str[i++] = source[start++];
	((int)option == 1) ? ft_strdel(&source) : 0;
	return (str);
}
