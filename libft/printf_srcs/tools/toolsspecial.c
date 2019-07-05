/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toolsspecial.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clonger <clonger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 23:18:57 by clonger           #+#    #+#             */
/*   Updated: 2018/03/12 17:12:32 by clonger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		not_this_one(char c, int option)
{
	if (c == 's' || c == 'p' || c == '%' || c == 'x' || c == 'o' || c == 'u')
		return (0);
	if (c == 'd' || c == 'i' || c == 'c' || ft_isdigit(c) || ft_isspace(c))
		return (0);
	if (c == '-' || c == '.')
		return (0);
	if (option)
	{
		if (c == 'l' || c == 'h' || c == 'j' || c == 'z' || c == '#')
			return (0);
		if (c == '+' || c == '-')
			return (0);
	}
	return (1);
}

void			ft_iszero(char *attribut, char *flag, char *str, char *which)
{
	intmax_t	nb;
	uintmax_t	unb;
	int			x;
	int			i;

	nb = 0;
	unb = 0;
	if (ft_isalpha(str[0]))
		return ;
	(ft_strequ(which, "signed")) ? (nb = ft_atoi(str)) : 0;
	(ft_strequ(which, "unsigned")) ? (unb = ft_atou(str)) : 0;
	if (nb != 0 || unb != 0 || !ft_strchr(flag, '.') ||
		(ft_strchr(attribut, '#') && !ft_strchr(flag, '.')))
		return ;
	if (ft_strchr(attribut, '#') && ft_is_flag(flag, 0, 1) == 'o')
		return ;
	else if (nb == 0 || unb == 0)
	{
		x = ft_charchr(flag, '.');
		i = ft_atoi(&flag[x + 1]);
		if (i > 0)
			return ;
		else
			str[0] = '\0';
	}
}

char			ft_isspecial_flag(char *str, int start)
{
	char		ret;
	char		lower;

	ret = 0;
	lower = 0;
	while (str[start] && !ret)
	{
		lower = ft_tolower(str[start]);
		if (not_this_one(lower, 0))
			ret = str[start];
		start++;
	}
	return (ret);
}

void			ft_init_struct(t_env *env)
{
	env->y1 = 0;
	env->y2 = 0;
	env->fd = 1;
	env->cflag = 0;
}
