/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clonger <clonger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 13:52:20 by clonger           #+#    #+#             */
/*   Updated: 2018/01/09 16:34:19 by clonger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putwchar_fd(wchar_t wchr, int fd)
{
	if (wchr <= 0x7F)
		ft_putchar_fd(wchr, fd);
	else if (wchr <= 0x7FF)
	{
		ft_putchar_fd((wchr >> 6) + 0xC0, fd);
		ft_putchar_fd((wchr & 0x3F) + 0x80, fd);
	}
	else if (wchr <= 0xFFFF)
	{
		ft_putchar_fd((wchr >> 12) + 0xE0, fd);
		ft_putchar_fd(((wchr >> 6) & 0x3F) + 0x80, fd);
		ft_putchar_fd((wchr & 0x3F) + 0x80, fd);
	}
	else if (wchr <= 0x10FFFF)
	{
		ft_putchar_fd((wchr >> 18) + 0xF0, fd);
		ft_putchar_fd(((wchr >> 12) & 0x3F) + 0x80, fd);
		ft_putchar_fd(((wchr >> 6) & 0x3F) + 0x80, fd);
		ft_putchar_fd((wchr & 0x3F) + 0x80, fd);
	}
}
