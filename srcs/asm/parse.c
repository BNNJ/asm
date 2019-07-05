/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clonger <clonger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 14:51:01 by clonger           #+#    #+#             */
/*   Updated: 2019/06/24 20:01:40 by clonger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		ft_res_inst(t_inst *inst)
{
	inst->opcode = 0;
	inst->pc_opcode = 0;
	inst->codage = 0;
	ft_bzero((void *)inst->typep, 4);
	ft_strdel(&inst->param[0]);
	ft_strdel(&inst->param[1]);
	ft_strdel(&inst->param[2]);
}

void			ft_parse(t_data *data, char *line, t_inst *inst)
{
	ft_res_inst(inst);
	if (ft_get_info(line, data))
	{
		ft_strdel(&line);
		return ;
	}
	if (ft_get_inst(line, inst, data))
	{
		ft_strdel(&line);
		return ;
	}
	asm_inst(inst, data);
	ft_strdel(&line);
}
