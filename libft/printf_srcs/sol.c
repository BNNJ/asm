/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sol.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clonger <clonger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 12:14:52 by clonger           #+#    #+#             */
/*   Updated: 2018/03/12 17:12:41 by clonger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_wdisplay(wchar_t *wtmp, char *flag, t_env *env)
{
	char		*str;
	int			length;

	str = ft_wstrtostr(wtmp);
	length = 0;
	if (!str)
	{
		length = ft_wstrlen(wtmp, "wstrlen");
		ft_putwstr_fd(wtmp, env->fd);
	}
	else
	{
		length = ft_strlen(str);
		if (ft_strchr(str, '\4'))
			ft_putnullstr_fd(str, flag, env->fd);
		else
			ft_putstr_fd(str, env->fd);
	}
	ft_strdel(&str);
	free(wtmp);
	return (length);
}

static int		ft_display(char **fill, t_env *env, char *flag, va_list *argv)
{
	wchar_t		*wtmp;
	int			length;

	length = 0;
	wtmp = NULL;
	env->cflag = ft_is_flag(flag, 0, 1);
	if (env->cflag != 'C' && env->cflag != 'S')
		length += ft_find_fd(fill, env, flag, argv);
	else
	{
		(env->cflag == 'C') ? wtmp = ft_printfwchar(argv, flag) : 0;
		(env->cflag == 'S') ? wtmp = ft_printfwstr(argv, flag) : 0;
		length += ft_wdisplay(wtmp, flag, env);
	}
	return (length);
}

int				ft_find_fd(char **fill, t_env *env, char *flag, va_list *argv)
{
	char		*tmp;
	int			length;

	length = 0;
	tmp = NULL;
	if (env->cflag == 'y')
		env->fd = va_arg(*argv, int);
	else
	{
		tmp = take_over2(fill, env, flag, argv);
		length += ft_strlen(tmp);
		if (env->cflag == 'c' && ft_strchr(tmp, '\4'))
			ft_putnullstr_fd(tmp, flag, env->fd);
		else
			ft_putstr_fd(tmp, env->fd);
		ft_strdel(&tmp);
	}
	return (length);
}

int				ft_begin_sol(char **fill, char **flag, va_list *argv)
{
	t_env		*env;
	int			length;

	if (!(env = (t_env *)malloc(sizeof(t_env))))
		return (0);
	length = 0;
	ft_init_struct(env);
	while (fill[env->y1])
	{
		if (flag[env->y2] && ft_strcmp(fill[env->y1], flag[env->y2]) == 0)
		{
			length += ft_display(fill, env, flag[env->y2], argv);
			env->y2++;
		}
		else
		{
			ft_putstr_fd(fill[env->y1], env->fd);
			length += ft_strlen(fill[env->y1]);
		}
		env->y1++;
	}
	ft_memdel((void **)&env);
	return (length);
}
