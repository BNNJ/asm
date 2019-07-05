/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clonger <clonger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 17:04:01 by clonger           #+#    #+#             */
/*   Updated: 2018/01/18 15:30:02 by clonger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_parseuns(char *str, char *flag)
{
	char		*ret;
	char		*attribut;
	int			x;
	int			i;
	int			j;

	attribut = ft_is_attributs(flag, 0);
	x = ft_charchr(flag, '.');
	ft_iszero(attribut, flag, str, "unsigned");
	if ((j = ft_atoi(&flag[x + 1])) && j > (int)ft_strlen(str))
		ret = ft_addncharfree(str, '0', j - ft_strlen(str), 0 + 0.0);
	else
		ret = ft_strsub(str, 0, ft_strlen(str));
	while ((!ft_isdigit(flag[x]) || ft_isdigit(flag[x - 1])) && flag[x - 1])
		x--;
	i = ft_atoi(&flag[x]);
	if (i > (int)ft_strlen(str))
		ret = ft_comp(ret, flag, 0, i - ft_strlen(ret));
	return (ret);
}

char			*ft_printfuns(va_list *argv, char *flag)
{
	char		*str;
	char		*varg;
	uintmax_t	vint;

	vint = va_arg(*argv, uintmax_t);
	vint = ft_changeusize(flag, vint);
	varg = ft_utoa(vint);
	if (ft_strlen(flag) > 2)
		str = ft_parseuns(varg, flag);
	else
		str = ft_strdup(varg);
	free(varg);
	return (str);
}
