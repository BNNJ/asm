/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isempty.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clonger <clonger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 13:22:44 by clonger           #+#    #+#             */
/*   Updated: 2018/01/09 13:31:22 by clonger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_isempty(char *str, size_t start, size_t length)
{
	if (!str)
		return (0);
	while (start <= length)
	{
		if (!ft_isspace(str[start]) && str[start])
			return (0);
		start++;
	}
	return (1);
}
