/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clonger <clonger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 15:12:46 by clonger           #+#    #+#             */
/*   Updated: 2018/01/19 16:16:29 by clonger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_parsebase(char *str, int basefrom, int baseto)
{
	char		*ret;
	char		*sbasefrom;
	char		*sbaseto;

	sbasefrom = ft_createbase(basefrom);
	sbaseto = ft_createbase(baseto);
	ret = ft_convert_base(str, sbasefrom, sbaseto);
	ft_strdel(&sbasefrom);
	ft_strdel(&sbaseto);
	return (ret);
}

char			*ft_printfbase(va_list *argv, char *flag)
{
	char		*str;
	char		*varg;
	uintmax_t	vint;
	int			x;
	int			i;

	x = ft_charchr(flag, '.');
	i = ft_atoi(&flag[x + 1]);
	while ((!ft_isdigit(flag[x]) || ft_isdigit(flag[x - 1])) && flag[x - 1])
		x--;
	x = ft_atoi(&flag[x]);
	(!i) ? i = 10 : 0;
	(!x) ? x = 10 : 0;
	if (x < 11)
	{
		vint = va_arg(*argv, uintmax_t);
		vint = ft_changeusize(flag, vint);
		varg = ft_utoa(vint);
	}
	else if (x > 10)
		varg = va_arg(*argv, char *);
	(i == 10 && x == 10) ? str = ft_strdup(varg) :
	(str = ft_parsebase(varg, x, i));
	(x < 11) ? ft_strdel(&varg) : 0;
	return (str);
}
