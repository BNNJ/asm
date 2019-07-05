/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_inst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clonger <clonger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 20:46:06 by clonger           #+#    #+#             */
/*   Updated: 2019/06/24 20:42:55 by clonger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void			get_first_inst(char *line, t_data *data)
{
	int				i;

	i = ft_charchr(line, LABEL_CHAR);
	if (i == (int)ft_strlen(line))
		return ;
	if (ft_strinbase(line, LABEL_CHARS, 0, i))
	{
		ft_create_label(ft_strsub(line, 0, i), data, data->pc, 'y');
		line = ft_strcpy(line, &line[i + 1]);
	}
}

static int			get_second_inst(char *line, t_data *data, t_inst *inst)
{
	int				i;
	int				y;
	int				j;

	j = 0;
	i = 0;
	if ((y = 0) == 0 && ft_isempty(line, 0, ft_strlen(line)))
		return (1);
	while (ft_isspace(line[j]))
		j++;
	while (!ft_isspace(line[j + i]))
		i++;
	while (y != 17)
	{
		if (ft_strnequ(&line[j], g_com[y].name, i))
			break ;
		else
			y++;
	}
	if (y == 17)
		ft_error("Opcode Error near", line);
	inst->opcode = g_com[y].opcode;
	inst->pc_opcode = data->pc;
	line = ft_strcpy(line, &line[j + i + 1]);
	return (0);
}

static void			get_third_inst(char *line, t_data *data, t_inst *inst)
{
	int				i;
	int				y;
	int				count;
	char			*param;

	i = 0;
	count = -1;
	if (ft_isempty(line, 0, ft_strlen(line)))
		ft_error("Param Error near", line);
	while (ft_isspace(line[i]))
		i++;
	y = ft_count_char(line, SEPARATOR_CHAR, i);
	if (y != (g_com[inst->opcode].nb_param - 1))
		ft_error("Param Error near", line);
	param = ft_strdup(line);
	y = 0;
	while (++count != g_com[inst->opcode].nb_param)
	{
		ft_strcut(param, 0, SEPARATOR_CHAR);
		ft_get_param(count, param, data, inst);
		y = ft_charnchr(line, y, SEPARATOR_CHAR) + 1;
		ft_strdel(&param);
		param = ft_strdup(&line[y]);
	}
	ft_strdel(&param);
}

int					ft_get_inst(char *line, t_inst *inst, t_data *data)
{
	get_first_inst(line, data);
	if (get_second_inst(line, data, inst))
		return (1);
	get_third_inst(line, data, inst);
	return (0);
}
