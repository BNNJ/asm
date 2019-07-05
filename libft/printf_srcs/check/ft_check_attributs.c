/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_attributs.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clonger <clonger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 13:06:56 by clonger           #+#    #+#             */
/*   Updated: 2018/01/23 12:02:04 by clonger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_override(char *flag, char cflag)
{
	char	*tmp;
	int		i;

	i = 1;
	while (ft_find_attributs(flag, i) != '3')
		i++;
	tmp = ft_strsub(flag, 1, i - 1);
	if (ft_strchr(tmp, '0') && ft_strchr(tmp, '-'))
		ft_delnchar(flag, '0', 1, ft_strlen(tmp));
	if (ft_strchr(tmp, '0') && ft_strchr(flag, '.') && cflag != 'c' &&
		ft_tolower(cflag) != 's' && cflag != '%' && ft_tolower(cflag) != 'f'
		&& cflag)
		ft_delnchar(flag, '0', 1, ft_strlen(tmp));
	if (ft_strchr(tmp, ' ') && ft_strchr(tmp, '+'))
		ft_delnchar(flag, ' ', 1, ft_strlen(tmp));
	ft_strdel(&tmp);
}

static int	ft_count_attributs(char *flag, int i)
{
	int		count;
	int		j;

	count = 0;
	j = i + 1;
	while (flag[j] && ft_find_attributs(flag, j) != '3')
	{
		if (ft_find_attributs(flag, j) != '3')
			count++;
		j++;
	}
	return (count);
}

char		*ft_is_attributs(char *flag, int start)
{
	char	*ret;
	char	cflag;

	ret = ft_all_attributs(flag, start);
	cflag = ft_tolower(ft_is_flag(flag, 0, 1));
	if (cflag == 'c' || cflag == 's')
		if (!ft_strchr(ret, '0'))
			(!ft_strchr(ret, '-')) ? (ft_strdel(&ret)) : 0;
	if (cflag == 'd' || cflag == 'i' || cflag == 'u')
		if (ft_strchr(ret, '#'))
			ft_delnchar(ret, '#', 0, ft_strlen(ret));
	if (cflag == 'o' || cflag == 'x' || cflag == 'u' || cflag == 'p' ||
		cflag == 'b')
	{
		if (ft_strchr(ret, '+'))
			ft_delnchar(ret, '+', 0, ft_strlen(ret));
		if (ft_strchr(ret, ' '))
			ft_delnchar(ret, ' ', 0, ft_strlen(ret));
	}
	if (ret && ft_find_attributs(ret, 0) == '3')
		ft_strdel(&ret);
	return (ret);
}

char		ft_find_attributs(char *flag, int start)
{
	char	c;

	c = '3';
	if (flag[start] == '#' || flag[start] == '-' || flag[start] == '+')
		c = flag[start];
	if (flag[start] == '0' || flag[start] == ' ')
		c = flag[start];
	return (c);
}

char		*ft_all_attributs(char *flag, int start)
{
	char	*ret;
	int		length;
	int		i;

	i = 0;
	ft_override(flag, ft_is_flag(flag, 0, 1));
	length = ft_count_attributs(flag, start);
	if (length == 0)
		return (NULL);
	(!start) ? (start = ft_charchr(flag, '%') + 1) : start;
	if (!(ret = ft_strnew(length)))
		return (NULL);
	ft_strclr(ret);
	while (ft_find_attributs(flag, start) != '3' && flag[start])
	{
		if (ft_find_attributs(flag, start) != '3')
			if (!ft_strchr(ret, flag[start]))
				ret[i++] = flag[start];
		start++;
	}
	ret[i] = '\0';
	return (ret);
}
