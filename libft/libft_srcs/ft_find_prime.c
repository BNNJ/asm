/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_prime.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clonger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 15:43:10 by clonger           #+#    #+#             */
/*   Updated: 2017/11/14 15:43:10 by clonger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_find_next_prime(size_t nb)
{
	size_t		number;

	number = 2;
	if (nb > 2)
	{
		if (nb > 3 && (nb % 2 == 0 || nb % 3 == 0))
			nb = ft_find_next_prime(nb + 1);
		else
		{
			while (number < nb / number)
			{
				if ((nb % number) != 0)
					number++;
				else
					nb = ft_find_next_prime(nb + 1);
			}
		}
	}
	if (nb < 3)
		return (2);
	if ((number == nb - 1) || nb > 1)
		return (nb);
	else
		return (0);
}

static size_t	ft_find_previous_prime(size_t nb)
{
	size_t		number;

	number = nb - 1;
	if (nb > 2)
	{
		if (nb > 3 && (nb % 2 == 0 || nb % 3 == 0))
			nb = ft_find_previous_prime(nb - 1);
		else
		{
			while (number > 2)
			{
				if ((nb % number) != 0)
					number--;
				else
					nb = ft_find_previous_prime(nb - 1);
			}
		}
	}
	if (nb == 2)
		return (2);
	if ((number == nb - 1) || nb > 1)
		return (nb);
	else
		return (0);
}

size_t			ft_find_prime(size_t nb, const char *which)
{
	if (!(ft_strcmp(which, "previous")))
		return (ft_find_previous_prime(nb));
	else if (!(ft_strcmp(which, "next")))
		return (ft_find_next_prime(nb));
	else
		return (0);
}
