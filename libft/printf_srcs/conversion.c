/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clonger <clonger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 10:22:33 by clonger           #+#    #+#             */
/*   Updated: 2018/01/25 18:12:15 by clonger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uintmax_t			ft_find_pow(uintmax_t nb, uintmax_t base)
{
	uintmax_t		result;
	uintmax_t		count;

	result = 1;
	count = 0;
	if (base > 0)
	{
		while (result <= nb && result)
		{
			result = base * result;
			count++;
		}
		return (count);
	}
	else
		return (0);
}

static uintmax_t	ft_atoi_base(char *str, char *base)
{
	uintmax_t		convert;
	uintmax_t		count;
	uintmax_t		num;
	uintmax_t		i;

	convert = 0;
	i = 0;
	count = ft_strlen(str);
	while (count != 0)
	{
		count--;
		num = ft_nbequ(str[i++]);
		convert = convert + (num * ft_pow(ft_strlen(base), count));
	}
	return (convert);
}

static char			*ft_itoa_base(uintmax_t nb, char *base)
{
	char			*str;
	uintmax_t		power;
	uintmax_t		div;
	uintmax_t		i;

	div = 0;
	i = 0;
	power = ft_find_pow(nb, ft_strlen(base));
	if (!(str = (char *)malloc(sizeof(char) * (power + 1))))
		return (NULL);
	while (power > 0)
	{
		div = nb / ((uintmax_t)ft_pow(ft_strlen(base), power - 1));
		nb = nb % ((uintmax_t)ft_pow(ft_strlen(base), power - 1));
		str[i] = ft_alphequ(div, base);
		i++;
		power--;
	}
	str[i] = '\0';
	return (str);
}

char				*ft_convert_base(char *s, char *basefrom, char *baseto)
{
	char			*str;
	uintmax_t		nb;

	if ((nb = 0) == 0 && (ft_atou(s) == ULONG_MAX || ft_atoi(s) == LONG_MIN))
		str = ft_check_valid_base(ft_atou(s), baseto);
	else
	{
		(s[0] == '0') ? str = ft_strdup("0\0") : 0;
		if (s[0] != '0')
		{
			if (ft_strlen(basefrom) == 10)
				str = ft_itoa_base(ft_atou(s), baseto);
			else if (ft_strlen(basefrom) != 10 && ft_strlen(baseto) == 10)
			{
				nb = ft_atoi_base(s, basefrom);
				str = ft_utoa(nb);
			}
			else if (ft_strlen(basefrom) != 10 && ft_strlen(baseto) != 10)
			{
				nb = ft_atoi_base(s, basefrom);
				str = ft_itoa_base(nb, baseto);
			}
		}
	}
	return (str);
}
