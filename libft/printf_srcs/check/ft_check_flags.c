/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clonger <clonger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 11:18:35 by clonger           #+#    #+#             */
/*   Updated: 2018/03/12 17:12:17 by clonger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_find_flags(char *str, int start)
{
	char		*flag;
	int			j;
	int			k;
	char		c;

	if ((j = ft_charnchr(str, start, '%')) != -1)
	{
		c = ft_is_flag(str, j, 0);
		if (!c)
			c = ft_isspecial_flag(str, start);
		k = ft_charnchr(str, j, c);
		flag = ft_strsub(str, j, (k - j) + 1);
	}
	else
		flag = NULL;
	return (flag);
}

int				ft_count_flags(char *str)
{
	int			i;
	int			count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%' && ft_is_flag(str, i, 1))
			count++;
		else if (str[i] == '%' && ft_isspecial_flag(str, i))
			count++;
		if (str[i] == '%' && ft_is_flag(str, i, 1) == '%')
		{
			while (str[i + 1] != '%')
				i++;
			i++;
		}
		i++;
	}
	return (count);
}

int				ft_is_percent(char *str, int start)
{
	if (!str)
		return (0);
	if (str[start] == '%')
	{
		start++;
		if (!ft_isspecial_flag(str, start) ||
		ft_charnchr(str, start, '%') <= ft_charnchr(str,
		start, ft_is_flag(str, start, 0)))
		{
			while (str[start] && str[start] != ft_is_flag(str, start, 0))
			{
				if (str[start] == '%')
					return (1);
				else
					start++;
			}
		}
	}
	return (0);
}

char			ft_is_flag(char *s, int st, int option)
{
	char		c;

	c = 0;
	while (s[st] && !c)
	{
		if (s[st] == '%' && option)
			if (ft_is_percent(s, st))
				return ('%');
		if (s[st] == 's' || s[st] == 'S' || s[st] == 'p')
			c = s[st];
		if (s[st] == 'd' || s[st] == 'D' || s[st] == 'i')
			c = s[st];
		if (s[st] == 'o' || s[st] == 'O' || s[st] == 'u')
			c = s[st];
		if (s[st] == 'U' || s[st] == 'x' || s[st] == 'X')
			c = s[st];
		if (s[st] == 'c' || s[st] == 'C' || s[st] == 'f')
			c = s[st];
		if (s[st] == 'F' || s[st] == 'b' || s[st] == 'k' || s[st] == 'y')
			c = s[st];
		if (ft_isgoodalpha(s[st]) && !c)
			return (0);
		st++;
	}
	return (c);
}

char			**ft_check_flags(char *str)
{
	char		**flag;
	int			y;
	int			i;
	int			mem_i;

	y = 0;
	i = -1;
	if (!(flag = (char **)malloc(sizeof(char *) * (ft_count_flags(str) + 1))))
		return (NULL);
	while (y < ft_count_flags(str) && str[++i])
	{
		if (str[i] == '%' && ft_is_flag(str, i, 1) == '%')
		{
			mem_i = i;
			i = ft_charnchr(str, i + 1, '%');
			flag[y++] = ft_strsub(str, mem_i, (i - mem_i) + 1);
		}
		else if (str[i] == '%')
		{
			i = ft_charnchr(str, i, '%');
			flag[y++] = ft_find_flags(str, i);
		}
	}
	flag[y] = NULL;
	return (flag);
}
