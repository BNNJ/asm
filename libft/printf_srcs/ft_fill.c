/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clonger <clonger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 13:48:04 by clonger           #+#    #+#             */
/*   Updated: 2018/01/06 14:21:38 by clonger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_doctor_strange(char *fmt, char **flag)
{
	int			i;
	int			y;
	int			count;

	i = 0;
	y = 0;
	count = 0;
	while (fmt[i])
	{
		if (flag[y] && ft_strnequ(&fmt[i], flag[y], ft_strlen(flag[y])))
		{
			count++;
			i += ft_strlen(flag[y]);
			y++;
		}
		else
		{
			count++;
			i = ft_charnchr(fmt, i, '%');
		}
	}
	return (count);
}

char			**ft_fill(char *format, char **flag)
{
	int			i;
	int			y;
	int			y2;
	int			doctor;
	char		**fill;

	i = 0;
	y = 0;
	y2 = 0;
	doctor = ft_doctor_strange(format, flag);
	if (!(fill = (char **)malloc(sizeof(char *) * (doctor + 1))))
		return (NULL);
	while (format[i])
	{
		if (!flag[y2])
			fill[y] = ft_strsub(format, i, ft_strlen(format) - i);
		else if (format[i] != '%')
			fill[y] = ft_strsub(format, i, ft_charnchr(format, i, '%') - i);
		else if (format[i] == '%' && flag[y2])
			fill[y] = ft_strdup(flag[y2++]);
		i += ft_strlen(fill[y++]);
	}
	fill[y] = NULL;
	return (fill);
}
