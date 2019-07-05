/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clonger <clonger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/31 16:25:12 by clonger           #+#    #+#             */
/*   Updated: 2018/01/03 15:15:35 by clonger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		take_dec(char *str, size_t precision, long double n)
{
	intmax_t	dec;
	int			x;

	dec = 0;
	if (n < 0)
		n *= -1;
	n -= (intmax_t)n;
	if (precision != 1)
	{
		dec = (n * precision);
		if (((intmax_t)(n * (precision * 10)) % 10) >= 5)
			dec++;
		str = ft_strcat(str, ft_itoa(dec));
	}
	else
	{
		x = ft_charchr(str, '.');
		if ((n * 10) >= 5)
			str[x - 1] = *ft_itoa(ft_atoi(&str[x - 1]) + 1);
		str[x] = '\0';
	}
}

char			*ft_ftoa(long double n, size_t precision)
{
	char		*str;
	char		*itoa;
	int			length;

	length = ft_countnb((intmax_t)n);
	if (!(str = ft_strnew(length + 7)))
		return (NULL);
	itoa = ft_itoa((intmax_t)n);
	str = ft_strcat(itoa, ".");
	take_dec(str, precision, n);
	return (str);
}
