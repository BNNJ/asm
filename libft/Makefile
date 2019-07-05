# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clonger <clonger@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/20 11:09:30 by clonger           #+#    #+#              #
#    Updated: 2019/07/04 23:52:19 by clonger          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a
SRC			=	printf_srcs/conversion.c \
				printf_srcs/ft_printf.c \
				printf_srcs/ft_fill.c \
				printf_srcs/ft_take_over.c \
				printf_srcs/ft_parse_attributs.c \
				printf_srcs/ft_parse_length.c \
				printf_srcs/sol.c \
				\
				printf_srcs/handle/string.c \
				printf_srcs/handle/char.c \
				printf_srcs/handle/convert.c \
				printf_srcs/handle/decimal.c \
				printf_srcs/handle/address.c \
				printf_srcs/handle/unsigned.c \
				printf_srcs/handle/wchar.c \
				printf_srcs/handle/wstr.c \
				printf_srcs/handle/percent.c \
				printf_srcs/handle/special.c \
				\
				printf_srcs/tools/toolsconvert.c \
				printf_srcs/tools/toolslength.c \
				printf_srcs/tools/toolsattributs.c \
				printf_srcs/tools/toolswchar.c \
				printf_srcs/tools/toolsspecial.c \
				\
				printf_srcs/bonus/float.c \
				printf_srcs/bonus/binary.c \
				printf_srcs/bonus/convert_b.c \
				\
				\
				libft_srcs/ft_memset.c \
				libft_srcs/ft_bzero.c \
				libft_srcs/ft_strlen.c \
				libft_srcs/ft_strdup.c \
				libft_srcs/ft_strcpy.c \
				libft_srcs/ft_strncpy.c \
				libft_srcs/ft_strcat.c \
				libft_srcs/ft_strncat.c \
				libft_srcs/ft_strlcat.c \
				libft_srcs/ft_strchr.c \
				libft_srcs/ft_strrchr.c \
				libft_srcs/ft_strstr.c \
				libft_srcs/ft_strnstr.c \
				libft_srcs/ft_strcmp.c \
				libft_srcs/ft_strncmp.c \
				libft_srcs/ft_atoi.c \
				libft_srcs/ft_isalpha.c \
				libft_srcs/ft_isdigit.c \
				libft_srcs/ft_isalnum.c \
				libft_srcs/ft_isascii.c \
				libft_srcs/ft_isprint.c \
				libft_srcs/ft_islower.c \
				libft_srcs/ft_isupper.c \
				libft_srcs/ft_toupper.c \
				libft_srcs/ft_tolower.c \
				libft_srcs/ft_memccpy.c \
				libft_srcs/ft_memcpy.c \
				libft_srcs/ft_memmove.c \
				libft_srcs/ft_memchr.c \
				libft_srcs/ft_memcmp.c \
				libft_srcs/ft_memalloc.c \
				libft_srcs/ft_memdel.c \
				libft_srcs/ft_strnew.c \
				libft_srcs/ft_strdel.c \
				libft_srcs/ft_strclr.c \
				libft_srcs/ft_putstr.c \
				libft_srcs/ft_striter.c \
				libft_srcs/ft_striteri.c \
				libft_srcs/ft_strmap.c \
				libft_srcs/ft_strmapi.c \
				libft_srcs/ft_strequ.c \
				libft_srcs/ft_strnequ.c \
				libft_srcs/ft_strsub.c \
				libft_srcs/ft_strjoin.c \
				libft_srcs/ft_strtrim.c \
				libft_srcs/ft_strsplit.c \
				libft_srcs/ft_itoa.c \
				libft_srcs/ft_putchar_fd.c \
				libft_srcs/ft_putchar.c \
				libft_srcs/ft_putstr_fd.c \
				libft_srcs/ft_putendl.c \
				libft_srcs/ft_putendl_fd.c \
				libft_srcs/ft_putnbr_fd.c \
				libft_srcs/ft_putnbr.c \
				libft_srcs/ft_lstnew.c \
				libft_srcs/ft_lstdelone.c \
				libft_srcs/ft_lstdel.c \
				libft_srcs/ft_isspace.c \
				libft_srcs/ft_lstadd.c \
				libft_srcs/ft_lstiter.c \
				libft_srcs/ft_lstmap.c \
				libft_srcs/ft_print_params_fd.c \
				libft_srcs/ft_sort_params_fd.c \
				libft_srcs/ft_pow.c \
				libft_srcs/ft_find_prime.c \
				libft_srcs/ft_strrev.c \
				libft_srcs/ft_operand.c \
				libft_srcs/ft_puttab.c \
				libft_srcs/ft_tab_to_str.c \
				libft_srcs/ft_puttabendl.c \
				libft_srcs/ft_charchr.c \
				libft_srcs/ft_charnchr.c \
				libft_srcs/ft_addnchar.c \
				libft_srcs/ft_delnchar.c \
				libft_srcs/ft_strcatsub.c \
				libft_srcs/ft_tabdup.c \
				libft_srcs/ft_putwchar_fd.c \
				libft_srcs/ft_putwstr_fd.c \
				libft_srcs/ft_putwchar.c \
				libft_srcs/ft_putwstr.c \
				libft_srcs/ft_utoa.c \
				libft_srcs/ft_wchrlen.c \
				libft_srcs/ft_addnwchar.c \
				libft_srcs/ft_wstrlen.c \
				libft_srcs/ft_wstrdup.c \
				libft_srcs/ft_tabdel.c \
				libft_srcs/ft_count_char.c \
				libft_srcs/ft_atou.c \
				libft_srcs/ft_wstrsub.c \
				libft_srcs/ft_ftoa.c \
				libft_srcs/ft_countnb.c \
				libft_srcs/ft_tablen.c \
				libft_srcs/ft_isempty.c \
				libft_srcs/ft_wstrtostr.c \
				libft_srcs/ft_addncharfree.c \
				libft_srcs/ft_strjoinfree.c \
				libft_srcs/ft_putcstr.c \
				libft_srcs/ft_vdelnchar.c \
				libft_srcs/ft_putnullstr_fd.c \
				libft_srcs/ft_only_number.c \
				libft_srcs/ft_is_tab_number.c \
				libft_srcs/get_next_line.c \
				libft_srcs/ft_count_word.c \
				libft_srcs/ft_is_int.c \
				libft_srcs/ft_tabrev.c \
				libft_srcs/ft_strcut.c \
				libft_srcs/ft_strinbase.c \
				\
				printf_srcs/check/ft_check_flags.c \
				printf_srcs/check/ft_check_length.c \
				printf_srcs/check/ft_check_fmt.c \
				printf_srcs/check/ft_check_attributs.c
OBJ			=	$(SRC:.c=.o)
INCLUDES	=	-I includes/
FLAGS		=	-Wall -Werror -Wextra

all : $(NAME)

# PROGRESS BAR
T = $(words $(OBJ))
N = 0
C = $(words $N)$(eval N := x $N)
ECHO = "[`expr $C  '*' 100 / $T`%]"

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

$(NAME):	name
		@printf "\n\t\t\033[32;1;3;4mLibft is ready\033[0m\n"

name:	$(OBJ)
		@ar rc $(NAME) $(OBJ)
		@ranlib $(NAME)

$(OBJ):	%.o: %.c
		@gcc $(FLAGS) $(INCLUDES) -c $< -o $@
		@printf "%-60b\r" "$(ECHO) $(_CYAN) Compiling $< $(_END)"

clean:
		@rm -f $(OBJ)
		@printf "\t\t\033[35;4;3mall libft_files.o are removed\033[0m\n"

fclean: clean
		@rm -f $(NAME)
		@printf "\t\t\033[31;1;3;4mlibft.a has been deleted\033[0m\n"

re: fclean all
