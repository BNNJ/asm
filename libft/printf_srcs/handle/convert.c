/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clonger <clonger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 15:55:40 by clonger           #+#    #+#             */
/*   Updated: 2019/06/28 01:28:38 by clonger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_parseoctal(char *str, char *flag)
{
	char		*ret;
	char		*attribut;
	int			x;
	int			i;
	int			j;

	ret = ft_convert_base(str, "0123456789", "01234567");
	attribut = ft_is_attributs(flag, 0);
	ft_iszero(attribut, flag, ret, "unsigned");
	if (!ft_strchr(flag, '.'))
		ret = ft_comp(ret, flag, 0, 0);
	x = ft_charchr(flag, '.');
	if ((j = ft_atoi(&flag[x + 1])) && j > (int)ft_strlen(ret))
		ret = ft_addncharfree(ret, '0', j - ft_strlen(ret), 0 + 0.1);
	while ((!ft_isdigit(flag[x]) || ft_isdigit(flag[x - 1])) && flag[x - 1])
		x--;
	i = ft_atoi(&flag[x]);
	if (i > (int)ft_strlen(ret))
		ret = ft_comp(ret, flag, 0, i - ft_strlen(ret));
	else if (!ft_strequ(ret, "0") && ft_strchr(flag, '.'))
		ret = ft_comp(ret, flag, 0, 0);
	ft_strdel(&attribut);
	return (ret);
}

char			*ft_parsehexa(char *str, char *flag, char *base)
{
	char		*ret;
	char		*attribut;
	int			x;
	int			i;
	int			j;

	ret = ft_convert_base(str, "0123456789", base);
	attribut = ft_is_attributs(flag, 0);
	ft_iszero(attribut, flag, ret, "unsigned");
	if (ft_strequ(ret, "0") || !*ret)
		ft_delnchar(flag, '#', 0, ft_strlen(flag));
	x = ft_charchr(flag, '.');
	if ((j = ft_atoi(&flag[x + 1])) && j > (int)ft_strlen(ret))
		ret = ft_addncharfree(ret, '0', (j - ft_strlen(ret)), 0 + 0.1);
	while ((!ft_isdigit(flag[x]) || ft_isdigit(flag[x - 1])) && flag[x - 1])
		x--;
	i = ft_atoi(&flag[x]);
	if (i > (int)ft_strlen(ret) - 2)
		ret = ft_comp(ret, flag, 0, i - (ft_strlen(ret)));
	else if (!ft_strequ(ret, "0"))
		ret = ft_comp(ret, flag, 0, 0);
	ft_strdel(&attribut);
	return (ret);
}

char			*ft_printfoctal(va_list *argv, char *flag)
{
	char		*str;
	char		*varg;
	uintmax_t	vint;

	vint = va_arg(*argv, uintmax_t);
	vint = ft_changeusize(flag, vint);
	varg = ft_utoa(vint);
	if (ft_strlen(flag) > 2)
		str = ft_parseoctal(varg, flag);
	else
		str = ft_convert_base(varg, "0123456789", "01234567");
	ft_strdel(&varg);
	return (str);
}

char			*ft_printfhexa(va_list *argv, char *flag, char cflag)
{
	char		*str;
	char		*varg;
	char		*base;
	uintmax_t	vint;

	vint = va_arg(*argv, uintmax_t);
	vint = ft_changeusize(flag, vint);
	varg = ft_utoa(vint);
	if (ft_islower(cflag))
		base = ft_strdup("0123456789abcdef");
	else
		base = ft_strdup("0123456789ABCDEF");
	if (ft_strlen(flag) > 2)
		str = ft_parsehexa(varg, flag, base);
	else
		str = ft_convert_base(varg, "0123456789", base);
	ft_strdel(&varg);
	ft_strdel(&base);
	return (str);
}
