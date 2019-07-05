/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clonger <clonger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 23:04:16 by clonger           #+#    #+#             */
/*   Updated: 2017/08/15 21:18:05 by clonger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_params_fd(int argc, char **argv, int fd)
{
	int i;

	i = 1;
	while (i != argc)
	{
		ft_putendl_fd(argv[i], fd);
		i++;
	}
}
