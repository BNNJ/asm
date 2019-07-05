/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toolsconvert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clonger <clonger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 17:23:22 by clonger           #+#    #+#             */
/*   Updated: 2018/01/19 17:04:07 by clonger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uintmax_t		ft_nbequ(uintmax_t c)
{
	uintmax_t	nb;

	nb = 0;
	if (ft_isdigit(c))
		nb = c - 48;
	if (ft_isupper(c))
		nb = c - 55;
	if (ft_islower(c))
		nb = c - 87;
	return (nb);
}

char			*ft_createbase(int nb)
{
	char		*str;
	int			i;

	i = -1;
	if (!(str = ft_strnew(nb)) || nb > 36)
		return (NULL);
	if (nb < 11)
		while (++i != nb)
			str[i] = i + 48;
	if (nb > 10)
	{
		while (++i != 10)
			str[i] = i + 48;
		i--;
		while (++i != nb)
			str[i] = 'A' + (i - 10);
	}
	str[i] = '\0';
	return (str);
}

char			ft_alphequ(uintmax_t nb, char *base)
{
	char		alph;
	uintmax_t	i;

	i = 0;
	while (base[i])
	{
		if (ft_isalpha(base[i]))
		{
			if (ft_islower(base[i]))
				alph = 'a';
			if (ft_isupper(base[i]))
				alph = 'A';
		}
		i++;
	}
	if (nb < 10)
		alph = nb + 48;
	if (nb > 10)
		alph = alph + (nb - 10);
	return (alph);
}

uintmax_t		ft_count_nb(uintmax_t nb)
{
	uintmax_t	count;

	count = 0;
	while (nb > 0)
	{
		nb /= 10;
		count++;
	}
	return (count);
}

char			*ft_check_valid_base(uintmax_t nb, char *base)
{
	char		*ret;
	int			i;

	i = 0;
	ret = NULL;
	if (nb == ULONG_MAX)
	{
		if (ft_strlen(base) == 8)
			ret = ft_strdup("1777777777777777777777");
		if (ft_strlen(base) == 2)
			ret = ft_strdup(BIN);
		if (ft_strlen(base) == 16)
		{
			while (ft_isdigit(base[i]))
				i++;
			if (ft_islower(base[i]))
				ret = ft_strdup("ffffffffffffffff");
			else if (ft_isupper(base[i]))
				ret = ft_strdup("FFFFFFFFFFFFFFFF");
		}
	}
	if ((intmax_t)nb == LONG_MIN)
		ret = ft_strdup("1000000000000000000000");
	return (ret);
}
