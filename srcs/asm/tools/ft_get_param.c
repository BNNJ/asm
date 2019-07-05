/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_param.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clonger <clonger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 19:56:34 by clonger           #+#    #+#             */
/*   Updated: 2019/06/24 21:12:26 by clonger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		get_codage(int code, t_inst *inst)
{
	int			shift;

	shift = 0;
	if (g_com[inst->opcode].codage == 'y')
	{
		if (code == -1)
		{
			shift = (4 - (g_com[inst->opcode].nb_param + 1));
			if (!shift % 2 == 0)
				shift = shift * 2;
			inst->codage = inst->codage << shift;
		}
		else
		{
			inst->codage = inst->codage | code;
			inst->codage = inst->codage << 2;
		}
	}
}

static void		get_reg(int num_param, char *param, t_inst *inst)
{
	int			reg;

	reg = ft_atoi(param);
	if (g_com[inst->opcode].param[num_param] & T_REG)
	{
		if (ft_only_number(param) && param[0] != '+' && param[0] != '-')
		{
			if (reg >= 0 && reg < 100)
			{
				inst->param[num_param] = ft_strdup(param);
				inst->typep[num_param] = T_REG;
				get_codage(REG_CODE, inst);
			}
			else
				ft_error("Register Error near ", param);
		}
		else
			ft_error("Register Error near ", param);
	}
	else
		ft_error("Register Error near ", param);
}

static void		get_direct(int num_param, char *param, t_data *data,
							t_inst *inst)
{
	int			i;

	i = 0;
	if (g_com[inst->opcode].param[num_param] & T_DIR)
	{
		if (param[0] == LABEL_CHAR)
		{
			if (ft_strinbase(param, LABEL_CHARS, ++i, -1))
				ft_label_call(ft_strdup(&param[i]), data, inst, DIR_SIZE);
			else
				ft_error("Direct Error near ", param);
			inst->param[num_param] = ft_strdup(param);
		}
		else
		{
			(param[i] == '-') ? i++ : 0;
			if (!ft_only_number(&param[i]) || param[i] == '-')
				ft_error("Direct Error near ", param);
			inst->param[num_param] = ft_strdup(param);
		}
		inst->typep[num_param] = T_DIR;
		get_codage(DIR_CODE, inst);
	}
	else
		ft_error("Direct Error near ", param);
}

static void		get_ind(int num_param, char *param, t_data *data, t_inst *inst)
{
	int			i;

	i = 0;
	if (g_com[inst->opcode].param[num_param] & T_IND)
	{
		if (param[0] == LABEL_CHAR)
		{
			if (ft_strinbase(param, LABEL_CHARS, ++i, -1))
				ft_label_call(&param[i], data, inst, IND_SIZE);
			else
				ft_error("Indirect Error near ", param);
			inst->param[num_param] = ft_strdup(param);
		}
		else
		{
			(param[i] == '-') ? i++ : 0;
			if (!ft_only_number(&param[i]) || param[i] == '-')
				ft_error("Indirect Error near ", param);
			inst->param[num_param] = ft_strdup(param);
		}
		inst->typep[num_param] = T_IND;
		get_codage(IND_CODE, inst);
	}
	else
		ft_error("Indirect Error near ", param);
}

void			ft_get_param(int num_param, char *param, t_data *data,
							t_inst *inst)
{
	int			i;

	i = 0;
	while (ft_isspace(param[i]))
		i++;
	if (param[i] == 'r')
		get_reg(num_param, &param[i + 1], inst);
	else if (param[i] == DIRECT_CHAR)
		get_direct(num_param, &param[i + 1], data, inst);
	else
		get_ind(num_param, &param[i], data, inst);
	if (num_param == g_com[inst->opcode].nb_param - 1)
		get_codage(-1, inst);
}
