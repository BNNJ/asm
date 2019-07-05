#include "asm.h"

t_com g_com[17] = {
	{ .name = "\0", .opcode = 0, .codage = 'n', .nb_param = 0, \
		.param = {0, 0, 0, 0}, .dir_size = 0 },
	{ .name = "live", .opcode = 1, .codage = 'n', .nb_param = 1, \
		.param = {T_DIR, 0, 0, 0}, .dir_size = 4 },
	{ .name = "ld", .opcode = 2, .codage = 'y', .nb_param = 2, \
		.param = {T_DIR + T_IND, T_REG, 0, 0}, .dir_size = 4 },
	{ .name = "st", .opcode = 3, .codage = 'y', .nb_param = 2, \
		.param = {T_REG, T_IND + T_REG, 0, 0}, .dir_size = 0 },
	{ .name = "add", .opcode = 4, .codage = 'y', .nb_param = 3, \
		.param = {T_REG, T_REG, T_REG, 0}, .dir_size = 0 },
	{ .name = "sub", .opcode = 5, .codage = 'y', .nb_param = 3, \
		.param = {T_REG, T_REG, T_REG, 0}, .dir_size = 0 },
	{ .name = "and", .opcode = 6, .codage = 'y', .nb_param = 3, \
		.param = {T_REG + T_DIR + T_IND, T_REG + T_DIR + T_IND, T_REG, 0}, \
		.dir_size = 4 },
	{ .name = "or", .opcode = 7, .codage = 'y', .nb_param = 3, \
		.param = {T_REG + T_DIR + T_IND, T_REG + T_DIR + T_IND, T_REG, 0}, \
		.dir_size = 4 },
	{ .name = "xor", .opcode = 8, .codage = 'y', .nb_param = 3, \
		.param = {T_REG + T_DIR + T_IND, T_REG + T_DIR + T_IND, T_REG, 0}, \
		.dir_size = 4 },
	{ .name = "zjmp", .opcode = 9, .codage = 'n', .nb_param = 1, \
		.param = {T_DIR, 0, 0, 0}, .dir_size = 2 },
	{ .name = "ldi", .opcode = 10, .codage = 'y', .nb_param = 3, \
		.param = {T_REG + T_DIR + T_IND, T_REG + T_DIR, T_REG, 0}, \
		.dir_size = 2 },
	{ .name = "sti", .opcode = 11, .codage = 'y', .nb_param = 3, \
		.param = {T_REG, T_REG + T_DIR + T_IND, T_REG + T_DIR, 0}, \
		.dir_size = 2 },
	{ .name = "fork", .opcode = 12, .codage = 'n', .nb_param = 1, \
		.param = {T_DIR, 0, 0, 0}, .dir_size = 2 },
	{ .name = "lld", .opcode = 13, .codage = 'y', .nb_param = 2, \
		.param = {T_DIR + T_IND, T_REG, 0, 0}, .dir_size = 4 },
	{ .name = "lldi", .opcode = 14, .codage = 'y', .nb_param = 3, \
		.param = {T_REG + T_DIR + T_IND, T_REG + T_DIR, T_REG, 0}, \
		.dir_size = 2 },
	{ .name = "lfork", .opcode = 15, .codage = 'n', .nb_param = 1, \
		.param = {T_DIR, 0, 0, 0}, .dir_size = 2 },
	{ .name = "aff", .opcode = 16, .codage = 'y', .nb_param = 1, \
		.param = {T_REG, 0, 0, 0}, .dir_size = 0 }
};
