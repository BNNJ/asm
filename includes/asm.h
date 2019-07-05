/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clonger <clonger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 17:58:08 by clonger           #+#    #+#             */
/*   Updated: 2019/06/26 16:12:46 by clonger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

//# include <string.h>
//# include <strings.h>
# include <stdlib.h>
//# include <ctype.h>
# include <unistd.h>
//# include <stdio.h>
//# include <sys/uio.h>
//# include <sys/types.h>
# include <fcntl.h>
//# include <wchar.h>
//# include <locale.h>
//# include <limits.h>
# include "ft_printf.h"
# include "op.h"

typedef struct			s_label
{
	char				*name;
	int					addr;
	unsigned char		visited;
	struct s_label		*next;
}						t_label;

typedef struct			s_no_label
{
	int					addr;
	int					addr_param;
	int					size_param;
	t_label				*label;
	struct s_no_label	*next;
}						t_no_label;

typedef struct			s_inst
{
	int					opcode;
	int					pc_opcode;
	char				codage;
	int					typep[MAX_ARGS_NUMBER];
	char				*param[MAX_ARGS_NUMBER];
}						t_inst;

typedef struct			s_data
{
	unsigned char		name;
	unsigned char		comment;
	int					pc;
	int					fd_cor;
	int					fd_s;
	int					coef_malloc;
	char				*bin;
	int					bin_length;
	t_label				*label;
	t_no_label			*no_label;
}						t_data;

typedef struct			s_com
{
	char				*name;
	int					opcode;
	unsigned char		codage;
	int					nb_param;
	int					param[MAX_ARGS_NUMBER];
	int					dir_size;
}						t_com;

t_com g_com[17];

int						main(int argc, const char **argv);
void					ft_parse(t_data *data, char *line, t_inst *inst);

/*
*** Init
*/

void					ft_init_data(t_data **data, const char *file);
void					ft_init_clabel(t_data **data, char *name, int addr,
										unsigned char visited);
void					ft_init_nlabel(t_data **data, t_label *label, int size);

/*
*** Del
*/

void					ft_del_data(t_data *data);
void					ft_del_inst(t_inst *inst);

/*
*** Handle
*/

int						asm_inst(t_inst *inst, t_data *data);
void					ft_realloc(t_data *data, int nb);
void					inc_pc(t_data *data, int nb);
void					calc_param(int p, t_inst *inst, t_data *data);
t_label					*ft_find_label(char *value, t_label *label);
t_no_label				*ft_find_nolabel(t_inst *inst, t_no_label *nolabel);
void					ft_calc_nolabel(t_data *data);
void					ft_calc_proglength(t_data *data);
void					ft_putnbrtostr(t_data *data, int pos, int n, int size);
void					ft_addnbrtostr(t_data *data, int n, int inc);

/*
*** Parse
*/

int						ft_get_inst(char *line, t_inst *inst, t_data *data);
int						ft_get_info(char *line, t_data *data);

/*
*** Tools
*/

void					ft_get_param(int num_param, char *param, t_data *data,
									t_inst *inst);
char					**ft_get_label(char *line, int **ret);
void					ft_create_label(char *name, t_data *data, int pc,
										unsigned char visited);
void					ft_label_call(char *name, t_data *data, t_inst *inst,
										int size);
char					*ft_dtoh(int n, int digit);
void					strrev(char *str);
void					ft_error(char *error, char *line);
int						ft_file_exists(t_data *data, char *file);

#endif
