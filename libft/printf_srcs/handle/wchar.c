/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wchar.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clonger <clonger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 15:48:36 by clonger           #+#    #+#             */
/*   Updated: 2018/01/25 19:44:58 by clonger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static wchar_t		*ft_parsewchar(wchar_t wchr, char *flag, int length)
{
	int				i;
	int				j;
	wchar_t			*ret;

	i = 0;
	j = ft_charchr(flag, '.');
	while ((!ft_isdigit(flag[j]) || ft_isdigit(flag[j - 1])) && flag[j - 1])
		j--;
	i = ft_atoi(&flag[j]);
	if (!(ret = ft_memalloc(sizeof(wchar_t) * length)))
		return (NULL);
	*ret = wchr;
	if (i > length)
		ret = ft_watt(ret, flag, 0, i - length);
	return (ret);
}

wchar_t				*ft_printfwchar(va_list *argv, char *flag)
{
	wchar_t			*wstr;
	wchar_t			wvarg;
	int				length;

	wvarg = (wchar_t)va_arg(*argv, wint_t);
	if (!(length = ft_wchrlen(wvarg)))
	{
		wstr = ft_wstrdup(L"\0");
		return (wstr);
	}
	(wvarg == '\0') ? length++ : 0;
	if (ft_strlen(flag) > 2)
		wstr = ft_parsewchar(wvarg, flag, length);
	else
	{
		if (!(wstr = ft_memalloc(sizeof(wchar_t) * length)))
			return (NULL);
		wstr[0] = wvarg;
	}
	if (wvarg == '\0')
		wstr[ft_wstrlen(wstr, "strlen")] = L'\4';
	else if (ft_strlen(flag) < 3)
		wstr[ft_wstrlen(wstr, "strlen")] = L'\0';
	return (wstr);
}
