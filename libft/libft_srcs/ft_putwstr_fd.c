/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clonger <clonger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 13:58:08 by clonger           #+#    #+#             */
/*   Updated: 2018/01/09 16:56:48 by clonger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putwstr_fd(wchar_t *wstr, int fd)
{
	int i;

	i = 0;
	while (wstr[i])
		ft_putwchar_fd(wstr[i++], fd);
}
