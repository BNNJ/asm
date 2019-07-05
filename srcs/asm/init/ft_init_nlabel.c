/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_nlabel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clonger <clonger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 17:43:57 by clonger           #+#    #+#             */
/*   Updated: 2019/06/26 14:52:55 by clonger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static t_no_label	*ft_new_label(t_label *label, int addr, int size)
{
	t_no_label		*no_label;

	if (!(no_label = (t_no_label *)ft_memalloc(sizeof(t_no_label))))
		return (NULL);
	no_label->addr = addr;
	no_label->size_param = size;
	no_label->label = label;
	return (no_label);
}

static void			ft_add_label(t_no_label *no_label, t_no_label *new)
{
	if (new == NULL)
		no_label = NULL;
	while (no_label)
	{
		if (no_label->next == NULL)
		{
			no_label->next = new;
			new->next = NULL;
		}
		no_label = no_label->next;
	}
}

void				ft_init_nlabel(t_data **data, t_label *label, int size)
{
	if ((*data)->no_label == NULL)
		(*data)->no_label = ft_new_label(label, (*data)->pc, size);
	else
		ft_add_label((*data)->no_label, ft_new_label(label, (*data)->pc, size));
}
