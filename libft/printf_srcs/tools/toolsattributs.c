/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toolsattributs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clonger <clonger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 11:49:14 by clonger           #+#    #+#             */
/*   Updated: 2018/01/01 17:32:39 by clonger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_is_compatible(char cflag, char attribut)
{
	int			ret;

	ret = 0;
	if (attribut == '-' || attribut == '0')
		ret = 1;
	if (attribut == '+')
		if (ft_tolower(cflag) == 'd' || cflag == 'i' ||
			ft_tolower(cflag) == 'f')
			ret = 1;
	if (attribut == '#')
	{
		if (ft_tolower(cflag) == 'o' || ft_tolower(cflag) == 'x')
			ret = 1;
		if (cflag == 'p' || cflag == 'b')
			ret = 1;
	}
	if (attribut == ' ')
		if (ft_tolower(cflag) == 'd' || cflag == 'i')
			ret = 1;
	return (ret);
}

char			*ft_which(char cflag)
{
	if (ft_tolower(cflag) == 'o')
		return ("0");
	if (cflag == 'x' || cflag == 'p')
		return ("0x");
	if (cflag == 'X')
		return ("0X");
	if (cflag == 'b')
		return ("0b");
	return (NULL);
}

size_t			ft_len(char *ret, ssize_t prelength, ssize_t length)
{
	ssize_t		newlength;
	size_t		retlen;

	newlength = 0;
	retlen = ft_strlen(ret);
	if ((ssize_t)retlen != prelength)
		newlength = length - (retlen - prelength);
	else
		newlength = length;
	if (newlength < 0)
		newlength = 0;
	return (newlength);
}
