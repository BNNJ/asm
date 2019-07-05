/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putcstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clonger <clonger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 11:26:05 by clonger           #+#    #+#             */
/*   Updated: 2018/02/02 12:29:30 by clonger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putcstr(char const *str, int c, int start)
{
	size_t	length;

	if (!str)
		ft_putstr("(null)");
	else if (!ft_strchr(str, c))
		ft_putstr("\0");
	else if (!c)
		write(1, &str[start], ft_strlen(str) - start);
	else
	{
		length = ft_charnchr(str, start, c);
		if (ft_isprint(c) && c != str[start])
			length++;
		write(1, &str[start], length - start);
	}
}
