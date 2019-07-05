/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clonger <clonger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 20:39:38 by clonger           #+#    #+#             */
/*   Updated: 2018/01/18 11:11:39 by clonger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_parsechar(char c, char *flag, int length)
{
	int			i;
	int			j;
	char		*ret;

	i = 0;
	j = ft_charchr(flag, '.');
	while ((!ft_isdigit(flag[j]) || ft_isdigit(flag[j - 1])) && flag[j - 1])
		j--;
	i = ft_atoi(&flag[j]);
	if (!(ret = ft_strnew(length)))
		return (NULL);
	*ret = c;
	if (i > 1)
		ret = ft_comp(ret, flag, 0, i - 1);
	return (ret);
}

char			*ft_printfchar(va_list *argv, char *flag)
{
	char		*str;
	char		varg;
	int			length;

	varg = (char)va_arg(*argv, int);
	length = 1;
	if (varg == '\0')
		length++;
	if (ft_strlen(flag) > 2)
		str = ft_parsechar(varg, flag, length);
	else
	{
		if (!(str = ft_strnew(length)))
			return (NULL);
		str[0] = varg;
	}
	if (varg == '\0')
		str = ft_strcat(str, "\4\0");
	else if (ft_strlen(flag) < 3)
		str = ft_strcat(str, "\0");
	return (str);
}
