/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_fmt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clonger <clonger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 23:34:10 by clonger           #+#    #+#             */
/*   Updated: 2018/01/20 17:25:59 by clonger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_rep(char *fmt, int start)
{
	char		tmp;
	char		tmp2;

	while (start <= (int)ft_strlen(fmt))
	{
		tmp = fmt[start];
		tmp2 = fmt[start + 1];
		fmt[start] = tmp2;
		fmt[start + 1] = tmp;
		start++;
	}
	fmt[start] = '\0';
}

static int		ft_good_count(char *str, char **flag)
{
	size_t		nbchar;
	int			i;
	int			y;

	i = 0;
	y = 0;
	if (!str || !flag)
		return (0);
	nbchar = ft_count_char(str, '%', 0);
	while (str[i] && flag[y])
	{
		if (ft_is_flag(flag[y], 0, 1) == '%')
		{
			y++;
			nbchar--;
		}
		else if (ft_is_flag(str, i, 1))
			y++;
		i++;
	}
	return (nbchar);
}

static int		ft_is_empty(char *str)
{
	int			i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			return (0);
		else
			i++;
	}
	return (1);
}

char			*ft_change_fmt(char *fmt, char **flag)
{
	int			i;
	int			y;
	char		*str;

	i = 0;
	y = 0;
	str = ft_strdup(fmt);
	if (ft_count_flags(str) != ft_good_count(str, flag))
	{
		while (str[i])
		{
			if (str[i] == '%' && (!flag[y] || !ft_strnequ(&str[i],
			flag[y], ft_strlen(flag[y]))))
			{
				ft_rep(str, i);
				y++;
			}
			else if (y < ft_count_flags(str))
				i += ft_strlen(flag[y++]) - 1;
			i++;
		}
	}
	if (ft_is_empty(str))
		ft_strclr(str);
	return (str);
}
