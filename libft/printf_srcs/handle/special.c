/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clonger <clonger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 00:10:56 by clonger           #+#    #+#             */
/*   Updated: 2018/01/18 15:30:43 by clonger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_parsespecial(char *flag)
{
	char		*str;
	int			x;
	int			i;

	x = 0;
	i = 0;
	x = ft_charchr(flag, '.');
	if (!(str = ft_strnew(1)))
		return (NULL);
	*str = ft_isspecial_flag(flag, 0);
	while ((!ft_isdigit(flag[x]) || ft_isdigit(flag[x - 1])) && flag[x - 1])
		x--;
	if ((i = ft_atoi(&flag[x])) && i > 1)
		i--;
	else
		i = 0;
	str = ft_comp(str, flag, 0, i);
	return (str);
}

char			*ft_printfspecial(char *flag)
{
	char		*str;

	str = ft_parsespecial(flag);
	return (str);
}
