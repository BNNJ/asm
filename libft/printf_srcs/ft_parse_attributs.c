/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_attributs.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clonger <clonger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 09:49:28 by clonger           #+#    #+#             */
/*   Updated: 2019/06/28 01:28:44 by clonger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_comp3(char *ret, char *flag, size_t prelength, char *att)
{
	char		cflag;

	cflag = ft_is_flag(flag, 0, 1);
	if (ft_strchr(att, '+') && ft_is_compatible(cflag, '+'))
	{
		if (ft_strchr(att, '0') && ft_strchr(ret, '0'))
			ret = ft_strcatsub("+", ret, '0', 0);
		else
			ret = ft_strjoinfree("+", ret, 2);
	}
	if (ft_strchr(att, ' ') && ft_is_compatible(cflag, ' '))
	{
		if (ret[0] == ' ')
			ret = ft_strcatsub(" ", ret, ' ', 0);
		else if (prelength == ft_strlen(ret))
			ret = ft_strjoinfree(" ", ret, 2);
		else if (ft_strchr(att, '0'))
			ret = ft_strcatsub(" ", ret, '0', 0);
		else
			ret = ft_strjoinfree(" ", ret, 2);
	}
	return (ret);
}

static char		*ft_comp2(char *ret, char *flag, size_t length, char *attribut)
{
	char		cflag;

	cflag = ft_is_flag(flag, 0, 1);
	if (ft_strchr(attribut, '0') && ft_is_compatible(cflag, '0'))
		ret = ft_addncharfree(ret, '0', length, 0 + 0.1);
	if (ft_strchr(attribut, '#') && ft_is_compatible(cflag, '#'))
	{
		if (ft_tolower(cflag) == 'o' && ret[0] == '0')
			ret = ft_strcatsub(ft_which(cflag), ret, '0', 0);
		else if ((ft_tolower(cflag) == 'x' || cflag == 'b') &&
			ft_strchr(attribut, '0') && ft_strchr(ret, '0'))
			ret = ft_strcatsub(ft_which(cflag), ret, '0', 0);
		else
			ret = ft_strjoinfree(ft_which(cflag), ret, 2);
	}
	return (ret);
}

char			*ft_comp(char *ret, char *flag, size_t start, size_t length)
{
	char		*attribut;
	char		cflag;
	size_t		prelength;

	cflag = ft_is_flag(flag, 0, 1);
	attribut = ft_is_attributs(flag, 0);
	prelength = ft_strlen(ret);
	if (attribut)
	{
		ret = ft_comp2(ret, flag, ft_len(ret, prelength, length), attribut);
		ret = ft_comp3(ret, flag, prelength, attribut);
		if (ft_strchr(attribut, '-') && ft_is_compatible(cflag, '-'))
			ret = ft_addncharfree(ret, ' ', ft_len(ret, prelength, length),
				ft_strlen(ret) + 0.1);
		ft_strdel(&attribut);
	}
	if (!attribut || !ft_strequ(attribut, "-") || !ft_strequ(attribut, "0"))
		ret = ft_addncharfree(ret, ' ', ft_len(ret, prelength, length),
			start + 0.1);
	return (ret);
}
