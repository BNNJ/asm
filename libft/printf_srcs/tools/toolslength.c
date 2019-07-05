/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toolslength.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clonger <clonger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 11:23:41 by clonger           #+#    #+#             */
/*   Updated: 2018/01/19 17:04:14 by clonger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_replacedel(char *flag, int start)
{
	char		tmp;

	tmp = flag[ft_strlen(flag) - 1];
	flag[start++] = tmp;
	while (flag[start])
		flag[start++] = '\0';
}

int				ft_isgoodalpha(int c)
{
	if (c == 'j' || c == 'z' || c == 'h' || c == 'l')
		return (0);
	if (c > 64 && c < 91)
		return (1);
	if (c > 96 && c < 123)
		return (1);
	return (0);
}

void			ft_replace(char **flag, int y)
{
	char cflag;

	cflag = ft_is_flag(flag[y], 0, 1);
	if (ft_strstr(flag[y], "ls"))
	{
		ft_delfchar(flag[y], 0);
		flag[y][ft_charchr(flag[y], 's')] = 'S';
	}
	if (ft_strstr(flag[y], "lc"))
	{
		ft_delfchar(flag[y], 0);
		flag[y][ft_charchr(flag[y], 'c')] = 'C';
	}
	if (cflag == 'D' || cflag == 'O' || cflag == 'U')
		flag[y][ft_charchr(flag[y], cflag)] = '\0';
	(cflag == 'D') ? ft_strcat(flag[y], "ld") : 0;
	(cflag == 'O') ? ft_strcat(flag[y], "lo") : 0;
	(cflag == 'U') ? ft_strcat(flag[y], "lu") : 0;
	if (cflag == 'F')
		flag[y][ft_charchr(flag[y], 'F')] = 'f';
}

void			ft_replace_all(char **fill, char **flag)
{
	int			y1;
	int			y2;

	y1 = -1;
	y2 = 0;
	while (fill[++y1])
	{
		if (ft_strequ(fill[y1], flag[y2]))
		{
			if (!ft_is_percent(flag[y2], 0))
			{
				ft_replace(flag, y2);
				ft_strdel(&fill[y1]);
				fill[y1] = ft_strdup(flag[y2]);
			}
			y2++;
		}
	}
}

void			ft_delfchar(char *flag, int start)
{
	size_t		length;
	char		*l;

	l = ft_is_length(flag, start);
	length = ft_strlen(l);
	if (l && ft_strnstr(&flag[start], l, length))
		ft_replacedel(flag, start);
	if (flag[start])
		ft_delfchar(flag, start + 1);
}
