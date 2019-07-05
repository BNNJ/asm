/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_take_over.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clonger <clonger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 14:49:42 by clonger           #+#    #+#             */
/*   Updated: 2018/03/12 17:12:52 by clonger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*take_over5(char *fill, char *flag, va_list *argv)
{
	char		cflag;

	cflag = ft_is_flag(flag, 0, 1);
	if (ft_tolower(cflag) == 'o')
		return (ft_printfoctal(argv, fill));
	if (ft_tolower(cflag) == 'x')
		return (ft_printfhexa(argv, fill, cflag));
	if (cflag == 'b')
		return (ft_printfbin(argv, fill));
	return (NULL);
}

static char		*take_over4(char *fill, char *flag, va_list *argv)
{
	char		cflag;

	cflag = ft_is_flag(flag, 0, 1);
	if (cflag == 'c')
		return (ft_printfchar(argv, fill));
	if (cflag == 's')
		return (ft_printfstr(argv, fill));
	if (cflag == '%')
		return (ft_printfper(fill));
	return (NULL);
}

static char		*take_over3(char *fill, char *flag, va_list *argv)
{
	char		cflag;

	cflag = ft_is_flag(flag, 0, 1);
	if (cflag == 'c' || cflag == 's' || cflag == '%')
		return (take_over4(fill, flag, argv));
	if (ft_tolower(cflag) == 'o' || ft_tolower(cflag) == 'x' || cflag == 'b')
		return (take_over5(fill, flag, argv));
	if (ft_tolower(cflag) == 'd' || cflag == 'i')
		return (ft_printfdec(argv, fill));
	if (cflag == 'p')
		return (ft_printfaddress(argv, fill));
	if (ft_tolower(cflag) == 'u')
		return (ft_printfuns(argv, fill));
	if (cflag == 'f')
		return (ft_printffloat(argv, fill));
	if (cflag == 'k')
		return (ft_printfbase(argv, fill));
	if (ft_isspecial_flag(fill, 0))
		return (ft_printfspecial(fill));
	return (NULL);
}

char			*take_over2(char **fill, t_env *env, char *flag, va_list *argv)
{
	char		*tmp;
	int			out;
	int			y;

	out = 0;
	y = env->y1;
	while (fill[y] && !out)
	{
		while (ft_strcmp(fill[y], flag) != 0)
			y++;
		if (ft_strcmp(fill[y], flag) == 0)
		{
			tmp = take_over3(fill[y], flag, argv);
			out = 1;
		}
		y++;
	}
	return (tmp);
}
