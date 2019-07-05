/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wstr.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clonger <clonger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 11:50:28 by clonger           #+#    #+#             */
/*   Updated: 2018/01/15 15:19:26 by clonger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static wchar_t	*ft_parsewstr(wchar_t *wstr, char *flag)
{
	int			x;
	int			i;
	int			length;
	wchar_t		*ret;

	x = ft_charchr(flag, '.');
	if (!ft_strchr(flag, '.'))
		i = ft_wstrlen(wstr, "wstrlen");
	else
		i = ft_atoi(&flag[x + 1]);
	ret = ft_wstrsub(wstr, 0, i);
	length = ft_wstrlen(ret, "wstrlen");
	while ((!ft_isdigit(flag[x]) || ft_isdigit(flag[x - 1])) && flag[x - 1])
		x--;
	i = ft_atoi(&flag[x]);
	if (i > length)
		ret = ft_watt(ret, flag, 0, i - length);
	return (ret);
}

wchar_t			*ft_printfwstr(va_list *argv, char *flag)
{
	wchar_t		*wstr;
	wchar_t		*wvarg;

	wvarg = va_arg(*argv, wchar_t *);
	if (wvarg == NULL)
		wstr = ft_wstrdup(L"(null)");
	else
	{
		if (!*wvarg)
			wstr = ft_wstrdup(L"\0");
		else
		{
			if (ft_strlen(flag) > 2)
				wstr = ft_parsewstr(wvarg, flag);
			else
				wstr = ft_wstrdup(wvarg);
		}
	}
	return (wstr);
}
