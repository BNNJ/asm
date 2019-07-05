/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addnchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flonger <flonger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 17:59:39 by clonger           #+#    #+#             */
/*   Updated: 2019/06/18 22:43:03 by flonger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_addnchar(char *source, int start, char c, int length)
{
	int		i;
	char	*str;

	i = -1;
	if (!source || !c)
		return (NULL);
	if (!(str = ft_strnew(ft_strlen(source) + length)))
		return (NULL);
	while (++i != start)
		str[i] = source[i];
	while (length--)
		str[i++] = c;
	while (source[start])
		str[i++] = source[start++];
	return (str);
}
