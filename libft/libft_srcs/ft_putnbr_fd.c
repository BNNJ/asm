/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clonger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 17:58:53 by clonger           #+#    #+#             */
/*   Updated: 2017/11/09 17:58:53 by clonger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		mod;
	int		div;
	int		min;

	min = 0;
	if (n == -2147483648)
	{
		min = n % 10 * (-1);
		n /= 10;
	}
	if (n < 0)
	{
		n *= (-1);
		ft_putchar_fd('-', fd);
	}
	if (n >= 0)
	{
		div = n / 10;
		mod = n % 10;
		if (div > 0)
			ft_putnbr_fd(div, fd);
		ft_putchar_fd(mod + 48, fd);
	}
	if (min > 0)
		ft_putchar_fd(min + 48, fd);
}
