/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clonger <clonger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 18:05:39 by clonger           #+#    #+#             */
/*   Updated: 2018/02/02 12:41:14 by clonger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_change(char *str, intmax_t n, int len)
{
	intmax_t	mod;

	if (n < 0)
	{
		n *= (-1);
		str[0] = '-';
	}
	while (n > 0)
	{
		mod = n % 10;
		n = n / 10;
		str[len--] = mod + 48;
	}
}

char			*ft_itoa(intmax_t n)
{
	intmax_t	length;
	char		*str;

	if (n == (-9223372036854775807) - 1)
		return (ft_strdup("-9223372036854775808"));
	length = ft_countnb(n) - 1;
	if (n == 0)
		return (ft_strdup("0"));
	str = ft_strnew(length + 1);
	if (!str)
		return (NULL);
	ft_change(str, n, length);
	return (str);
}
