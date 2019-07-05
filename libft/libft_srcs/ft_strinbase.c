/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strinbase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clonger <clonger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 15:43:42 by clonger           #+#    #+#             */
/*   Updated: 2019/06/11 16:09:19 by clonger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_strinbase(char *str, char *base, int start, int length)
{
	(length == -1) ? length = ft_strlen(str) : 0;
	while (str[start])
	{
		if (start == length)
			break ;
		if (!ft_strchr(base, str[start]))
			return (0);
		start++;
	}
	return (1);
}
