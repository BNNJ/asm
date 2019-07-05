/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clonger <clonger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 21:42:20 by clonger           #+#    #+#             */
/*   Updated: 2017/12/23 21:49:12 by clonger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_count_char(const char *str, char c, int start)
{
	size_t		count;

	count = 0;
	if (!str || !c)
		return (0);
	while (str[start])
	{
		if (str[start] == c)
			count++;
		start++;
	}
	return (count);
}
