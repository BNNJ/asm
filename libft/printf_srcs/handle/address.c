/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   address.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clonger <clonger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 16:01:03 by clonger           #+#    #+#             */
/*   Updated: 2018/01/16 11:36:09 by clonger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_parseaddress(char *str, char *flag, char *base)
{
	char		*ret;
	int			x;
	int			i;
	int			j;

	ret = ft_convert_base(str, "0123456789", base);
	ft_iszero(NULL, flag, ret, "unsigned");
	x = ft_charchr(flag, '.');
	if ((j = ft_atoi(&flag[x + 1])) && j > (int)ft_strlen(ret))
		ret = ft_addncharfree(ret, '0', j - ft_strlen(ret), 0 + 0.1);
	while ((!ft_isdigit(flag[x]) || ft_isdigit(flag[x - 1])) && flag[x - 1])
		x--;
	i = ft_atoi(&flag[x]);
	if (ft_strchr(ft_is_attributs(flag, 0), '0'))
		i -= 2;
	if (i > (int)ft_strlen(ret) - 2)
		ret = ft_comp(ret, flag, 0, i - ft_strlen(ret));
	else
		ret = ft_comp(ret, flag, 0, 0);
	return (ret);
}

char			*ft_printfaddress(va_list *argv, char *flag)
{
	char		*str;
	void		*vaddress;
	char		*varg;
	char		*base;
	char		*baseten;

	vaddress = va_arg(*argv, void *);
	varg = ft_itoa((size_t)vaddress);
	base = ft_strdup("0123456789abcdef");
	baseten = ft_strdup("0123456789");
	if (ft_strlen(flag) > 2 && !ft_strchr(flag, '#'))
		flag = ft_addncharfree(flag, '#', 1, 1 + 0.0);
	if (ft_strlen(flag) > 2)
		str = ft_parseaddress(varg, flag, base);
	else
		str = ft_strjoinfree("0x", ft_convert_base(varg, baseten, base), 2);
	ft_strdel(&varg);
	ft_strdel(&base);
	ft_strdel(&baseten);
	return (str);
}
