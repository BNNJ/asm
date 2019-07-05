/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clonger <clonger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 15:51:04 by clonger           #+#    #+#             */
/*   Updated: 2018/01/18 15:29:49 by clonger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_parseper(char c, char *flag)
{
	int			i;
	int			x;
	char		*ret;

	x = ft_charchr(flag, '.');
	while ((!ft_isdigit(flag[x]) || ft_isdigit(flag[x - 1])) && flag[x - 1])
		x--;
	i = ft_atoi(&flag[x]);
	if (!(ret = ft_strnew(1)))
		return (NULL);
	*ret = c;
	if (i > 1)
		ret = ft_comp(ret, flag, 0, i - 1);
	return (ret);
}

char			*ft_printfper(char *flag)
{
	char		*str;
	char		varg;

	varg = '%';
	if (ft_strlen(flag) > 2)
		str = ft_parseper(varg, flag);
	else
	{
		if (!(str = ft_strnew(1)))
			return (NULL);
		str[0] = varg;
		str[1] = '\0';
	}
	return (str);
}
