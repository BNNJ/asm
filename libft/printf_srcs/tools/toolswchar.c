/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toolswchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clonger <clonger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 17:56:07 by clonger           #+#    #+#             */
/*   Updated: 2018/01/19 18:05:38 by clonger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

wchar_t			*ft_watt(wchar_t *ret, char *flag, int start, int length)
{
	char	*attribut;
	char	cflag;

	cflag = ft_is_flag(flag, 0, 1);
	attribut = ft_is_attributs(flag, 0);
	if (attribut)
	{
		if (ft_strchr(attribut, '-') && ft_is_compatible(cflag, '-'))
			ret = ft_addnwchar(ret, ft_wstrlen(ret, "strlen"), ' ', length);
		if (ft_strchr(attribut, '0') && ft_is_compatible(cflag, '0'))
			ret = ft_addnwchar(ret, 0, '0', length);
	}
	if (!attribut)
		ret = ft_addnwchar(ret, start, ' ', length);
	return (ret);
}

int				ft_iswchar(wchar_t *str)
{
	int			i;

	i = 0;
	while (str[i])
	{
		if (ft_wchrlen(str[i]) > 1)
			return (1);
		i++;
	}
	return (0);
}
