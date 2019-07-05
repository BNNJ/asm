/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charnchr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clonger <clonger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 11:55:37 by clonger           #+#    #+#             */
/*   Updated: 2018/02/02 12:23:41 by clonger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_charnchr(const char *str, int start, int c)
{
	if (!str)
		return (0);
	if (!c)
		return (ft_strlen(str));
	while (str[start])
	{
		if (str[start] == c)
			return (start);
		else
			start++;
	}
	return (ft_strlen(str));
}
