/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clonger <clonger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 14:56:18 by clonger           #+#    #+#             */
/*   Updated: 2019/06/24 20:50:53 by clonger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			ft_addnbrtostr(t_data *data, int n, int inc)
{
	int			l;
	int			c;

	l = data->bin_length;
	if (n < 0)
	{
		n = n + (int)ft_pow((double)2, (double)(inc * 8));
	}
	while (inc != 0)
	{
		c = n / (int)ft_pow((double)256, (double)(inc - 1));
		data->bin[l] = c;
		n = n - c * (int)ft_pow((double)256, (double)(inc - 1));
		inc--;
		l++;
	}
}

static void		put_param(int p, t_inst *inst, t_data *data, int inc)
{
	t_label		*ptrlabel;
	t_no_label	*ptrnolabel;
	int			offset;

	ft_realloc(data, inc);
	if (inst->param[p][0] == LABEL_CHAR)
	{
		ptrlabel = ft_find_label(&inst->param[p][1], data->label);
		offset = (ptrlabel->addr - inst->pc_opcode);
		ft_addnbrtostr(data, offset, inc);
		if (ptrlabel->visited == 'n')
		{
			ptrnolabel = ft_find_nolabel(inst, data->no_label);
			ptrnolabel->addr_param = data->pc;
		}
	}
	else
		ft_addnbrtostr(data, atoi(inst->param[p]), inc);
	inc_pc(data, inc);
}

void			ft_realloc(t_data *data, int nb)
{
	if (data->pc + nb >= data->coef_malloc * BBS)
	{
		data->coef_malloc++;
		data->bin = realloc(data->bin, FULL_LENGTH + data->coef_malloc * BBS);
	}
}

void			inc_pc(t_data *data, int nb)
{
	data->pc = data->pc + nb;
	data->bin_length = data->bin_length + nb;
}

void			calc_param(int p, t_inst *inst, t_data *data)
{
	int			inc;
	int			l;

	if (inst->typep[p] == T_REG)
	{
		ft_realloc(data, 1);
		l = data->bin_length;
		data->bin[l] = atoi(inst->param[p]);
		inc_pc(data, 1);
	}
	else if (inst->typep[p] == T_DIR)
	{
		inc = g_com[inst->opcode].dir_size;
		put_param(p, inst, data, inc);
	}
	else if (inst->typep[p] == T_IND)
	{
		inc = IND_SIZE;
		put_param(p, inst, data, inc);
	}
	else
		ft_error("Error not a valid param", NULL);
}
