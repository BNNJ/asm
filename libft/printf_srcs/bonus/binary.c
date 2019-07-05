/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clonger <clonger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/01 16:52:44 by clonger           #+#    #+#             */
/*   Updated: 2019/06/18 19:32:40 by clonger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_parsebin(char *str, char *flag)
{
	char		*ret;
	char		*attribut;
	int			x;
	int			i;
	int			j;

	ret = ft_convert_base(str, "0123456789", "01");
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
	return (ret);
}

char			*ft_printfbin(va_list *argv, char *flag)
{
	char		*str;
	char		*varg;
	uintmax_t	vint;

	vint = va_arg(*argv, uintmax_t);
	vint = ft_changeusize(flag, vint);
	varg = ft_utoa(vint);
	if (ft_strlen(flag) > 2)
		str = ft_parsebin(varg, flag);
	else
		str = ft_convert_base(varg, "0123456789", "01");
	ft_strdel(&varg);
	return (str);
}
