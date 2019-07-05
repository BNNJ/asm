/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_label.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clonger <clonger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 14:43:44 by clonger           #+#    #+#             */
/*   Updated: 2019/06/24 20:50:20 by clonger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void				ft_create_label(char *name, t_data *data, int pc,
								unsigned char visited)
{
	t_label			*label;

	label = ft_find_label(name, data->label);
	if (!label)
		ft_init_clabel(&data, name, pc, visited);
	else if (label->visited == 'n')
	{
		ft_strdel(&name);
		label->addr = data->pc;
		label->visited = 'y';
	}
	else
		ft_error("Lexical Error at ", name);
	if (data->label == NULL)
		ft_error("Error Malloc", NULL);
}

void				ft_label_call(char *name, t_data *data, t_inst *inst,
								int size)
{
	t_label			*label;

	label = ft_find_label(name, data->label);
	if (!label)
	{
		ft_init_clabel(&data, name, 0, 'n');
		label = ft_find_label(name, data->label);
	}
	else
		ft_strdel(&name);
	if (size == DIR_SIZE)
		size = g_com[inst->opcode].dir_size;
	ft_init_nlabel(&data, label, size);
	if (data->no_label == NULL)
		ft_error("Error Malloc", NULL);
}

t_label				*ft_find_label(char *value, t_label *label)
{
	t_label		*ptr;

	ptr = label;
	if (value == NULL)
		ft_error("Error null label", NULL);
	while (ptr)
	{
		if (ft_strequ(ptr->name, value))
			return (ptr);
		ptr = ptr->next;
	}
	return (NULL);
}

t_no_label			*ft_find_nolabel(t_inst *inst, t_no_label *nolabel)
{
	t_no_label		*ptr;

	ptr = nolabel;
	if (inst == NULL)
		ft_error("Error no param", NULL);
	while (ptr != NULL)
	{
		if (ptr->addr == inst->pc_opcode)
			return (ptr);
		ptr = ptr->next;
	}
	return (NULL);
}
