/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clonger <clonger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 11:31:48 by clonger           #+#    #+#             */
/*   Updated: 2017/08/16 13:47:36 by clonger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_sort_params_fd(int argc, char **argv, int fd)
{
	int		cmp;
	int		i;
	char	*tmp;

	i = 1;
	while (i != argc - 1)
	{
		cmp = ft_strcmp(argv[i], argv[i + 1]);
		if (cmp > 0)
		{
			tmp = argv[i];
			argv[i] = argv[i + 1];
			argv[i + 1] = tmp;
			i = 0;
		}
		i++;
	}
	ft_print_params_fd(argc, argv, fd);
}
