/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnullstr_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clonger <clonger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 16:52:19 by clonger           #+#    #+#             */
/*   Updated: 2018/03/12 17:14:57 by clonger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putnullstr_fd(char const *str, char *flag, int fd)
{
	if (!ft_strchr(flag, '-'))
	{
		write(fd, str, ft_strlen(str) - 1);
		ft_putchar_fd('\0', fd);
	}
	else
	{
		ft_putchar_fd('\0', fd);
		write(fd, str, ft_strlen(str) - 1);
	}
}
