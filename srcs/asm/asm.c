/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clonger <clonger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 19:10:07 by clonger           #+#    #+#             */
/*   Updated: 2019/06/28 16:05:31 by clonger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void			ft_create_cor(char *file, t_data *data)
{
	int				i;
	int				ret;
	char			*str;

	strrev(file);
	i = ft_charchr(file, '.');
	file = ft_strcpy(file, &file[i]);
	strrev(file);
	str = ft_strjoin(file, "cor");
	if ((ret = ft_file_exists(data, str)) == 1)
		data->fd_cor = open(str, O_CREAT | O_RDWR | O_TRUNC,
					S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	else if (ret == -1)
		return ;
	strrev(str);
	ft_strcut(str, 0, '/');
	strrev(str);
	ft_printf("Writing output program to %s\n", str);
	ft_strdel(&str);
	write(data->fd_cor, data->bin, data->bin_length);
	close(data->fd_cor);
}

static void			ft_get_champ(t_data *data)
{
	char			*line;
	int				ret;
	t_inst			*inst;

	if (!(inst = (t_inst *)ft_memalloc(sizeof(t_inst))))
		return ;
	while ((ret = get_next_line(data->fd_s, &line)))
	{
		if (ret == -1)
			ft_error("Error line", NULL);
		if (ft_count_char(line, '#', 0))
			if (ft_charchr(line, '#') != 1)
				ft_strcut(line, 0, '#');
		if (!ft_isempty(line, 0, ft_strlen(line)))
			ft_parse(data, ft_strtrim(line), inst);
		ft_strdel(&line);
	}
	close(data->fd_s);
	ft_strdel(&line);
	ft_del_inst(inst);
}

int					main(int argc, const char **argv)
{
	t_data			*data;

	data = NULL;
	if (argc == 1)
		ft_putendl("Usage: ./asm <sourcefile.s>");
	ft_init_data(&data, argv[1]);
	if (data->fd_s == -1)
		ft_error("Can\'t read source file ", (char *)argv[argc - 1]);
	ft_get_champ(data);
	ft_calc_nolabel(data);
	ft_calc_proglength(data);
	ft_create_cor((char *)argv[1], data);
//  prtbin(data);
	ft_del_data(data);
	return (0);
}
