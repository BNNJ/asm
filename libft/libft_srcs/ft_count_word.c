/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clonger <clonger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 16:10:03 by clonger           #+#    #+#             */
/*   Updated: 2018/02/09 20:47:22 by clonger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_count_word(const char *str)
{
	int		i;
	size_t	count;

	i = 0;
	count = 0;
	if (!str)
		return (0);
	while (!ft_isalnum(str[i]))
		i++;
	while (str[i])
	{
		if (!ft_isalnum(str[i]))
		{
			count++;
			while (!ft_isalnum(str[i]) && str[i])
				i++;
		}
		else if (ft_isalnum(str[i]))
			i++;
		if (ft_isalnum(str[i]) && str[i + 1] == '\0')
			count++;
	}
	return (count);
}
