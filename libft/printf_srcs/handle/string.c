/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clonger <clonger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 15:33:03 by clonger           #+#    #+#             */
/*   Updated: 2019/06/28 01:28:35 by clonger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_parsestr(char *str, char *flag)
{
	char		*ret;
	int			x;
	int			i;

	x = ft_charchr(flag, '.');
	i = ft_atoi(&flag[x + 1]);
	(!ft_strchr(flag, '.')) ? (i = (int)ft_strlen(str)) : i;
	(i > (int)ft_strlen(str)) ? (i = (int)ft_strlen(str)) : i;
	if (!*str)
		ret = ft_strdup("\0");
	else
		ret = ft_strsub(str, 0, i);
	while ((!ft_isdigit(flag[x]) || ft_isdigit(flag[x - 1])) && flag[x - 1])
		x--;
	i = ft_atoi(&flag[x]);
	if (i > (int)ft_strlen(ret))
		ret = ft_comp(ret, flag, 0, i - ft_strlen(ret));
	return (ret);
}

char			*ft_printfstr(va_list *argv, char *flag)
{
	char		*str;
	char		*varg;
	char		*snull;

	varg = va_arg(*argv, char *);
	snull = ft_strdup("(null)");
	if (varg == NULL)
		str = ft_parsestr(snull, flag);
	else if (ft_strlen(flag) > 2)
		str = ft_parsestr(varg, flag);
	else
		str = ft_strdup(varg);
	ft_strdel(&snull);
	return (str);
}
