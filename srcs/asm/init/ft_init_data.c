/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flonger <flonger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 14:10:33 by clonger           #+#    #+#             */
/*   Updated: 2019/06/27 19:01:22 by flonger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void				ft_init_data(t_data **data, const char *file)
{
	int				len_bin;

	if (!((*data) = (t_data *)ft_memalloc(sizeof(t_data))))
		return ;
	(*data)->fd_s = open(file, O_RDWR);
	(*data)->name = 'n';
	(*data)->comment = 'n';
	(*data)->bin_length = FULL_LENGTH;
	len_bin = FULL_LENGTH;
	if (!((*data)->bin = (char *)ft_memalloc(len_bin + 1)))
		ft_error("Error Malloc", NULL);
	ft_bzero((void *)(*data)->bin, len_bin);
	ft_putnbrtostr(*data, 0, COREWAR_EXEC_MAGIC, MAGIC_LENGTH);
	ft_putnbrtostr(*data, MAGIC_LENGTH + NAME_LENGTH,
					OPTION1, OPTION1_LENGTH);
	ft_putnbrtostr(*data, MAGIC_LENGTH + NAME_LENGTH
					+ OPTION1_LENGTH + PROGSIZE_LENGTH
					+ COMMENT_LENGTH, OPTION2, OPTION2_LENGTH);
}
