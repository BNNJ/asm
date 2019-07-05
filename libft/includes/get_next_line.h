/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clonger <clonger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 14:58:51 by clonger           #+#    #+#             */
/*   Updated: 2019/06/24 16:56:00 by clonger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 4096
# include "libft.h"
# include <sys/uio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <stdio.h>

typedef struct		s_line
{
	int				fd;
	char			*line;
	struct s_line	*next;
}					t_line;

int					get_next_line(const int fd, char **line);

#endif
