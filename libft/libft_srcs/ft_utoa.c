/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clonger <clonger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 15:27:41 by clonger           #+#    #+#             */
/*   Updated: 2018/02/02 12:53:18 by clonger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count(uintmax_t n)
{
	uintmax_t	i;

	i = 0;
	if (n == 0)
		i = 1;
	while (n > 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

static void		ft_change(char *str, uintmax_t n, int len)
{
	uintmax_t	mod;

	while (n > 0)
	{
		mod = n % 10;
		n = n / 10;
		str[len--] = mod + 48;
	}
}

char			*ft_utoa(uintmax_t n)
{
	uintmax_t	length;
	char		*str;

	length = ft_count(n) - 1;
	if (n == 0)
		return (ft_strdup("0"));
	str = ft_strnew(length + 1);
	if (!str)
		return (NULL);
	ft_change(str, n, length);
	return (str);
}
