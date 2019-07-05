/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clonger <clonger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/04 11:33:27 by zaz               #+#    #+#             */
/*   Updated: 2019/06/28 01:54:05 by clonger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Toutes les tailles sont en octets.
** On part du principe qu'un int fait 32 bits. Est-ce vrai chez vous ?
*/

#ifndef OP_H
# define OP_H

# define BBS					1024

# define IND_SIZE				2
# define REG_SIZE				4
# define DIR_SIZE				REG_SIZE
# define OPC_SIZE				1
# define COD_SIZE				1

# define REG_CODE				1
# define DIR_CODE				2
# define IND_CODE				3

# define MAX_ARGS_NUMBER		4
# define MAX_PLAYERS			4
# define MEM_SIZE				(4*1024)
# define IDX_MOD				(MEM_SIZE / 8)
# define CHAMP_MAX_SIZE			(MEM_SIZE / 6)

# define COMMENT_CHAR			'#'
# define LABEL_CHAR				':'
# define DIRECT_CHAR			'%'
# define SEPARATOR_CHAR			','

# define LABEL_CHARS			"abcdefghijklmnopqrstuvwxyz_0123456789"

# define BASE_CHARS				"abcdefghijklmnopqrstuvwxyz_0123456789#:%,-\t "

# define HEXA_BASE				"0123456789abcdef"

# define NAME_CMD_STRING		".name"
# define COMMENT_CMD_STRING		".comment"

# define REG_NUMBER				16

# define CYCLE_TO_DIE			1536
# define CYCLE_DELTA			50
# define NBR_LIVE				21
# define MAX_CHECKS				10

typedef char	t_arg_type;

# define T_REG					1
# define T_DIR					2
# define T_IND					4
# define T_LAB					8

# define MAGIC_LENGTH			(4)
# define COREWAR_EXEC_MAGIC		0xea83f3
//# define COREWAR_EXEC_MAGIC		0x88fcf019
# define NAME_LENGTH			(128)
# define OPTION1_LENGTH			(4)
# define OPTION1				0x00
# define PROGSIZE_LENGTH		(4)
# define COMMENT_LENGTH			(2048)
# define OPTION2_LENGTH			(4)
# define OPTION2				0x00
# define A_LENGTH				(MAGIC_LENGTH + NAME_LENGTH + OPTION1_LENGTH)
# define B_LENGTH				(PROGSIZE_LENGTH + COMMENT_LENGTH) 
# define C_LENGTH				(OPTION2_LENGTH)
# define FULL_LENGTH			(A_LENGTH + B_LENGTH + C_LENGTH)

typedef struct		s_header
{
	unsigned int		magic;
	char				prog_name[NAME_LENGTH + 1];
	unsigned int		prog_size;
	char				comment[COMMENT_LENGTH + 1];
}					t_header;

#endif
