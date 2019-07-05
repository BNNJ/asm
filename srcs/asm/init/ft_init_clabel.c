/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_clabel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clonger <clonger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 10:11:47 by clonger           #+#    #+#             */
/*   Updated: 2019/06/24 20:33:48 by clonger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static t_label		*ft_new_label(char *name, int pc, unsigned char visited)
{
	t_label			*label;

	if (!(label = (t_label *)ft_memalloc(sizeof(t_label))))
		return (NULL);
	label->name = name;
	label->addr = pc;
	label->visited = visited;
	label->next = NULL;
	return (label);
}

static void			ft_add_label(t_label *label, t_label *new)
{
	if (new == NULL)
		label = NULL;
	while (label)
	{
		if (label->next == NULL)
		{
			label->next = new;
			new->next = NULL;
		}
		label = label->next;
	}
}

void				ft_init_clabel(t_data **data, char *name, int addr,
					unsigned char visited)
{
	if ((*data)->label == NULL)
		(*data)->label = ft_new_label(name, addr, visited);
	else
		ft_add_label((*data)->label, ft_new_label(name, addr, visited));
}
