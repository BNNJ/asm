# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clonger <clonger@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/02 13:51:14 by clonger           #+#    #+#              #
#    Updated: 2019/07/04 23:52:31 by clonger          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	asm
SRCS_A		=	srcs/asm/asm.c \
				srcs/asm/parse.c \
				srcs/asm/tools/ft_label.c \
				srcs/asm/tools/ft_bin.c \
				srcs/asm/tools/ft_get_param.c \
				srcs/asm/tools/tools.c \
				srcs/asm/handle/asm_inst.c \
				srcs/asm/parse/ft_get_info.c \
				srcs/asm/parse/ft_get_inst.c \
				srcs/asm/init/ft_init_data.c \
				srcs/asm/init/ft_init_clabel.c \
				srcs/asm/init/ft_init_nlabel.c \
				srcs/asm/del/del_data.c \
				srcs/asm/op.c
OBJS_A		=	$(SRCS_A:.c=.o)
INCLUDES	=	-I libft/includes -I includes/
LIBS		=	-L libft/ -lft
FLAGS		=	-Wall -Wextra -Werror

# PROGRESS BAR
T = $(words $(OBJS_A))
N = 0
C = $(words $N)$(eval N := x $N)
ECHOC = "[`expr $C '*' 100 / $T`%]"

#Colors
_GREY=\x1b[30m
_RED=\x1b[31m
_GREEN=\x1b[32m
_YELLOW=\x1b[33m
_BLUE=\x1b[34m
_PURPLE=\x1b[35m
_CYAN=\x1b[36m
_WHITE=\x1b[37m
_END=\x1b[0m

all	: lib $(NAME)

lib:
		@printf "\n\t\t\033[3;1mCreating libft.a...\033[0m\n"
		@make -C libft/
		@printf "\n$(_BLUE)==========================================================\n$(_END)"
		@printf "\n\t\t\033[3;1mCreating $(NAME)...\033[0m\n"

name: $(OBJS_A)
		@gcc -o $(NAME) $(OBJS_A) $(LIBS)

$(NAME): name
		@printf "\n\t\t\033[32;1;3;4mAsm is ready\033[0m\n\n"
		@printf "$(_YELLOW)==========================================================\n$(_END)"

$(OBJS_A): %.o: %.c
		@gcc $(FLAGS) $(INCLUDES) -c $< -o $@
		@printf "%-60b\r" "$(ECHOC) $(_CYAN) Compiling $< $(_END)"

clean:
		@rm -f $(OBJS_A)
		@printf "\n\t\033[35;4;3mall asm_files.o are removed\033[0m\n"
		@make -C libft/ clean
		@printf "$(_WHITE)==========================================================\n\n$(_END)"

fclean:
		@rm -f $(NAME)
		@rm -f $(OBJS_A)
		@printf "\n\t\033[35;4;3mall asm_files.o are removed\033[0m\n"
		@make -C libft/ fclean
		@printf "\t\033[31;1;3;4masm has been deleted\033[0m\n"
		@printf "$(_RED)==========================================================\n$(_END)"

re: fclean all
