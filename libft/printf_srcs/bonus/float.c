/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clonger <clonger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/31 17:06:09 by clonger           #+#    #+#             */
/*   Updated: 2018/01/05 15:06:11 by clonger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_parsefloat(long double vint, char *flag)
{
	char		*ret;
	char		*attribut;
	int			x;
	int			i;

	x = ft_charchr(flag, '.');
	i = ft_atoi(&flag[x + 1]);
	attribut = ft_is_attributs(flag, 0);
	if (!ft_strchr(flag, '.'))
		i = 6;
	ret = ft_ftoa(vint, ft_pow(10, i));
	while ((!ft_isdigit(flag[x]) || ft_isdigit(flag[x - 1])) && flag[x - 1])
		x--;
	i = ft_atoi(&flag[x]);
	if (i > (int)ft_strlen(ret))
		ret = ft_comp(ret, flag, 0, i - ft_strlen(ret));
	if (ft_strchr(attribut, '+') && !ft_strchr(ret, '+'))
		ret = ft_comp(ret, flag, 0, 0);
	if (ft_strchr(attribut, ' ') && !ft_strchr(ret, ' '))
		ret = ft_comp(ret, flag, 0, 0);
	return (ret);
}

static char		*add_sign(char *str, char *flag, long double vint)
{
	char		*attribut;
	char		*ret;
	int			i;

	attribut = ft_is_attributs(flag, 0);
	i = 0;
	if (ft_strchr(str, '+'))
		ret = ft_strcatsub("-", str, '+', ft_charchr(str, '+'));
	else if (ft_strchr(str, '0'))
		ret = ft_strcatsub("-", str, '0', ft_charchr(str, '0'));
	else if (ft_strchr(str, ' ') && !ft_strchr(attribut, '-'))
	{
		while (ft_isspace(str[i]) && str[i])
			i++;
		ret = ft_strcatsub("-", str, ' ', i - 1);
	}
	else if (ft_strlen(str) == ft_count_nb(vint))
		ret = ft_strjoinfree("-", str, 0);
	else
		return (NULL);
	return (ret);
}

char			*ft_printffloat(va_list *argv, char *flag)
{
	char		*str;
	int			sign;
	long double vint;

	vint = va_arg(*argv, double);
	sign = 1;
	if (vint < 0)
	{
		flag = ft_addncharfree(flag, '+', 1, 1 + 0.1);
		sign = -1;
	}
	if (ft_strlen(flag) > 2)
		str = ft_parsefloat(vint * sign, flag);
	else
		str = ft_ftoa(vint * sign, ft_pow(10, 6));
	if (vint < 0)
		str = add_sign(str, flag, vint * sign);
	return (str);
}
