/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_inst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clonger <clonger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 14:56:25 by clonger           #+#    #+#             */
/*   Updated: 2019/06/28 01:12:26 by clonger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			ft_putnbrtostr(t_data *data, int pos, int n, int size)
{
	int			i;
	char		*ptr;

	ptr = (char *)&n;
	i=size - 1;
	while (i>=0)
	{
		data->bin[pos + size - i - 1] = ptr[i];
		i--;
	}
}

int				asm_inst(t_inst *inst, t_data *data)
{
	int			p;
	int			i;
	int			l;

	ft_realloc(data, OPC_SIZE);
	l = data->bin_length;
	data->bin[l] = inst->opcode;
	inc_pc(data, OPC_SIZE);
	if (g_com[inst->opcode].codage == 'y')
	{
		ft_realloc(data, COD_SIZE);
		l = data->bin_length;
		data->bin[l] = inst->codage;
		inc_pc(data, COD_SIZE);
	}
	i = 0;
	p = g_com[inst->opcode].nb_param;
	while (i < p)
	{
		calc_param(i, inst, data);
		i++;
	}
	return (0);
}

void			ft_calc_nolabel(t_data *data)
{
	t_no_label	*nolabel;
	int			l;
	int			nbr;

	l = FULL_LENGTH;
	nolabel = data->no_label;
	if (!nolabel)
		return ;
	while (nolabel->next != NULL)
	{
		nbr = nolabel->label->addr - nolabel->addr;
		ft_putnbrtostr(data, l + nolabel->addr_param, nbr, nolabel->size_param);
		nolabel = nolabel->next;
	}
}

void			ft_calc_proglength(t_data *data)
{
	ft_putnbrtostr(data, MAGIC_LENGTH + NAME_LENGTH + OPTION1_LENGTH, data->pc,
					PROGSIZE_LENGTH);
	// ft_putnbrtostr(data, MAGIC_LENGTH + NAME_LENGTH + OPTION1_LENGTH, 407,
					// PROGSIZE_LENGTH);

	// ft_putnbrtostr(data, MAGIC_LENGTH + NAME_LENGTH + OPTION1_LENGTH, 4653,
					// PROGSIZE_LENGTH);
}
