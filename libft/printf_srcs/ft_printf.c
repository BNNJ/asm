/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clonger <clonger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 16:41:23 by clonger           #+#    #+#             */
/*   Updated: 2018/01/23 14:34:03 by clonger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_printf(const char *format, ...)
{
	va_list		ap;
	char		**flag;
	char		**fill;
	char		*newfmt;
	int			length;

	va_start(ap, format);
	flag = ft_check_flags((char *)format);
	newfmt = ft_change_fmt((char *)format, flag);
	fill = ft_fill(newfmt, flag);
	ft_replace_all(fill, flag);
	length = ft_begin_sol(fill, flag, &ap);
	ft_tabdel(fill);
	ft_tabdel(flag);
	ft_strdel(&newfmt);
	va_end(ap);
	return (length);
}
