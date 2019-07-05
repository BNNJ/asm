/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clonger <clonger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 07:28:57 by clonger           #+#    #+#             */
/*   Updated: 2019/05/07 14:26:24 by clonger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_parsedec(char *str, char *flag)
{
	char		*ret;
	char		*attribut;
	int			x;
	int			i;
	int			j;

	attribut = ft_is_attributs(flag, 0);
	x = ft_charchr(flag, '.');
	ft_iszero(attribut, flag, str, "signed");
	if (ft_strchr(flag, flag[x + 1]) && (j = ft_atoi(&flag[x + 1])) &&
	j > (int)ft_strlen(str))
		ret = ft_addncharfree(str, '0', j - ft_strlen(str), 0 + 0.0);
	else
		ret = ft_strsub(str, 0, ft_strlen(str));
	while ((!ft_isdigit(flag[x]) || ft_isdigit(flag[x - 1])) && flag[x - 1])
		x--;
	i = ft_atoi(&flag[x]);
	if (i > (int)ft_strlen(str))
		ret = ft_comp(ret, flag, 0, i - ft_strlen(ret));
	if (ft_strchr(attribut, '+') && !ft_strchr(ret, '+'))
		ret = ft_comp(ret, flag, 0, 0);
	if (ft_strchr(attribut, ' ') && !ft_strchr(ret, ' '))
		ret = ft_comp(ret, flag, 0, 0);
	ft_strdel(&attribut);
	return (ret);
}

static char		*add_sign(char *str, char *flag, intmax_t vint)
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

char			*ft_printfdec(va_list *argv, char *flag)
{
	char		*str;
	char		*varg;
	intmax_t	vint;

	vint = va_arg(*argv, intmax_t);
	vint = ft_changesize(flag, vint);
	(vint >= 0) ? varg = ft_itoa(vint) : 0;
	if (vint < 0)
	{
		flag = ft_addncharfree(flag, '+', 1, 1 + 0.0);
		varg = ft_itoa(-vint);
	}
	if (ft_strlen(flag) > 2)
		str = ft_parsedec(varg, flag);
	else
		str = ft_strdup(varg);
	ft_strdel(&varg);
	if (vint < 0)
		str = add_sign(str, flag, -vint);
	return (str);
}
