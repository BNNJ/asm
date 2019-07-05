/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clonger <clonger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 15:02:45 by clonger           #+#    #+#             */
/*   Updated: 2017/12/02 14:23:06 by clonger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strrev(char *s)
{
	char		*str;
	int			length;
	int			i;

	length = ft_strlen(s);
	i = 0;
	if (!(str = ft_strnew(length)))
		return (NULL);
	length--;
	while (s[i])
	{
		str[length] = s[i];
		length--;
		i++;
	}
	return (str);
}
