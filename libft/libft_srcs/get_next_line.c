/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clonger <clonger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 12:31:06 by clonger           #+#    #+#             */
/*   Updated: 2019/06/24 17:56:03 by clonger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_line				*lst_new(const int fd)
{
	t_line			*new;

	if (!(new = (t_line *)ft_memalloc(sizeof(t_line))))
		return (NULL);
	new->fd = fd;
	new->line = ft_strnew(0);
	new->next = NULL;
	return (new);
}

void				lst_add(t_line *str, t_line *new)
{
	while (str)
	{
		if (str->next == NULL)
		{
			str->next = new;
			new->next = NULL;
		}
		str = str->next;
	}
}

int					ft_read(int fd, t_line *list)
{
	char			buf[BUFF_SIZE + 1];
	int				ret;
	char			*tmp;

	tmp = NULL;
	while (!ft_strchr(list->line, '\n'))
	{
		if ((ret = read(fd, buf, BUFF_SIZE)) < 0)
			return (-1);
		else
		{
			buf[ret] = 0;
			tmp = list->line;
			if (!(list->line = ft_strjoin(list->line, buf)))
				return (-1);
			ft_strdel(&tmp);
		}
		if (ret < BUFF_SIZE)
			return (ret);
	}
	return (ret);
}

char				*ft_take_line(t_line *list, char **line)
{
	char			*str;
	char			*tmp;
	int				i;

	i = 0;
	str = list->line;
	tmp = NULL;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			*line = ft_strsub(str, 0, i);
			tmp = str;
			str = ft_strdup(str + (i + 1));
			free(tmp);
			return (str);
		}
		i++;
	}
	*line = ft_strdup(str);
	ft_strclr(str);
	ft_strclr(list->line);
	return (str);
}

int					get_next_line(const int fd, char **line)
{
	static t_line	*file;
	t_line			*tmp;
	int				ret;

	if (!file)
		file = lst_new(fd);
	tmp = file;
	if (fd < 0 || !line)
		return (-1);
	while (tmp)
	{
		if (tmp->fd == fd)
			break ;
		if (tmp->next == NULL)
			lst_add(tmp, lst_new(fd));
		tmp = tmp->next;
	}
	if ((ret = ft_read(fd, tmp)) == -1)
		return (-1);
	tmp->line = ft_take_line(tmp, line);
	if (!ft_strlen(tmp->line) && !ft_strlen(*line) && !ret)
		return (0);
	else
		return (1);
}
