/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clonger <clonger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 18:53:16 by clonger           #+#    #+#             */
/*   Updated: 2019/06/24 20:02:12 by clonger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			ft_del_inst(t_inst *inst)
{
	ft_strdel(&inst->param[0]);
	ft_strdel(&inst->param[1]);
	ft_strdel(&inst->param[2]);
	ft_memdel((void **)&inst);
}

void			ft_del_label(t_label **label)
{
	t_label		*tmp;

	tmp = *label;
	while (*label)
	{
		tmp = *label;
		ft_strdel(&tmp->name);
		(*label) = (*label)->next;
		tmp->next = NULL;
		ft_memdel((void **)&tmp);
	}
}

void			ft_del_nlabel(t_no_label **no_label)
{
	t_no_label	*tmp;

	tmp = *no_label;
	while (*no_label)
	{
		tmp = *no_label;
		(*no_label) = (*no_label)->next;
		tmp->next = NULL;
		ft_memdel((void **)&tmp);
	}
}

void			ft_del_data(t_data *data)
{
	ft_del_label(&data->label);
	ft_del_nlabel(&data->no_label);
	ft_memdel((void **)&data->label);
	ft_memdel((void **)&data->no_label);
	ft_strdel(&data->bin);
	ft_memdel((void **)&data);
}
