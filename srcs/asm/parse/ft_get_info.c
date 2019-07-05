/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flonger <flonger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 18:38:39 by clonger           #+#    #+#             */
/*   Updated: 2019/06/27 19:01:21 by flonger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		ft_get_name(char *line, t_data *data)
{
	int			i;

	if (line)
	{
		i = 0;
		while (line[i] != '\0')
		{
			data->bin[MAGIC_LENGTH + i] = line[i];
			i++;
		}
		data->name = 'y';
	}
}

static void		ft_get_comment(char *line, t_data *data)
{
	int			i;

	if (line)
	{
		i = 0;
		while (line[i] != '\0')
		{
			data->bin[MAGIC_LENGTH + NAME_LENGTH
			+ OPTION1_LENGTH + PROGSIZE_LENGTH + i] = line[i];
			i++;
		}
		data->comment = 'y';
	}
}

int				ft_get_info(char *line, t_data *data)
{
	int			char_id;

	char_id = ft_charchr(line, '\"');
	if (ft_strnequ(line, NAME_CMD_STRING, 5) && data->name == 'n')
	{
		if (ft_count_char(line, '\"', 0) == 2)
		{
			ft_vdelnchar(line, '\"', 0, ft_strlen(line));
			ft_get_name(&line[char_id], data);
		}
		return (1);
	}
	else if (ft_strnequ(line, COMMENT_CMD_STRING, 8) && data->comment == 'n')
	{
		if (ft_count_char(line, '\"', 0) == 2)
		{
			ft_vdelnchar(line, '\"', 0, ft_strlen(line));
			ft_get_comment(&line[char_id], data);
		}
		return (1);
	}
	else if (!ft_strinbase(line, BASE_CHARS, 0, -1)
			|| data->name == 'n' || data->comment == 'n')
		ft_error("Line Error near ", line);
	return (0);
}
