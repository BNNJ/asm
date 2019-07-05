/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clonger <clonger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 23:43:01 by clonger           #+#    #+#             */
/*   Updated: 2019/06/26 00:47:22 by clonger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void				strrev(char *str)
{
	char			tmp;
	int				i;
	int				end;
	size_t			length;

	i = 0;
	end = 0;
	tmp = 0;
	end = ft_strlen(str) - 1;
	length = ft_strlen(str);
	if (length % 2)
		length++;
	length /= 2;
	while (i != (int)length)
	{
		tmp = str[end];
		str[end] = str[i];
		str[i] = tmp;
		i++;
		end--;
	}
}

// void				ft_print_bin(t_data *data)
// {
// 	int				start;
// 	int				end;

// 	start = 0;
// 	end = data->bin_length - 1;
// 	while (start <= end)
// 	{
// 		ft_printf("%.2x", (unsigned char)(data->bin[start]));
// 		if (start != end)
// 			ft_putchar(' ');
// 		start++;
// 	}
// }

int					ft_file_exists(t_data *data, char *file)
{
	char			*line;

	line = NULL;
	if ((data->fd_cor = open(file, O_EXCL | O_CREAT | O_RDWR | O_TRUNC,
							 S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) != -1)
		return (0);
	else
	{
		ft_printf("The file %s already exists.\nDo you want to rewrite it ? \
[y/n] ", file);
		if (get_next_line(0, &line) == -1)
			ft_error("Error line", NULL);
		ft_putendl("");
		if (ft_strequ(line, "y"))
		{
			ft_strdel(&line);
			return (1);
		}
		else
			printf("The file %s was not changed.\n", file);
	}
	ft_strdel(&line);
	return (-1);
}

void				ft_error(char *error, char *str)
{
	ft_putstr(error);
	if (str)
		ft_putendl(str);
	else
		ft_putendl("");
	exit(EXIT_FAILURE);
}
