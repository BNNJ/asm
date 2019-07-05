/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clonger <clonger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 10:23:06 by clonger           #+#    #+#             */
/*   Updated: 2018/03/12 17:13:54 by clonger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <string.h>
# include <strings.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/uio.h>
# include <sys/types.h>
# include <stdarg.h>
# include <wchar.h>
# include <stdint.h>
# include <inttypes.h>
# include <locale.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "libft.h"

# define BIN "1111111111111111111111111111111111111111111111111111111111111111"

typedef struct	s_env
{
	int			y1;
	int			y2;
	int			fd;
	char		cflag;
}				t_env;

/*
*** Fonction pour le printf
*/

int				ft_check_wcarg(va_list *argv, char **flag, int y, int option);
int				ft_check_wsarg(va_list *argv, char **flag, int y, int option);
int				ft_check_arg(va_list *argv, char **flag, int y, int option);
int				ft_begin_sol(char **fill, char **flag, va_list *argv);
int				ft_is_compatible(char cflag, char attribut);
int				ft_is_percent(char *str, int start);
int				ft_count_flags(char *str);
int				ft_iswchar(wchar_t *str);
int				ft_isgoodalpha(int c);
char			*take_over2(char **fill, t_env *env, char *flag, va_list *argv);
char			*ft_comp(char *ret, char *flag, size_t start, size_t length);
char			*ft_convert_base(char *s, char *basefrom, char *baseto);
char			*ft_printfhexa(va_list *argv, char *flag, char cflag);
char			*ft_find_length(char *flag, char cflag, int start);
char			*ft_parsehexa(char *str, char *flag, char *base);
char			*ft_check_valid_base(uintmax_t nb, char *base);
char			ft_is_flag(char *str, int start, int option);
char			*ft_printfaddress(va_list *argv, char *flag);
char			*ft_printfoctal(va_list *argv, char *flag);
char			*ft_printfchar(va_list *argv, char *flag);
char			*ft_all_attributs(char *flag, int start);
char			ft_find_attributs(char *flag, int start);
char			*ft_printfdec(va_list *argv, char *flag);
char			*ft_printfuns(va_list *argv, char *flag);
char			*ft_printfstr(va_list *argv, char *flag);
char			*ft_is_attributs(char *flag, int start);
char			ft_isspecial_flag(char *str, int start);
char			*ft_change_fmt(char *fmt, char **flag);
char			*ft_is_length(char *flag, int start);
char			**ft_fill(char *format, char **flag);
char			ft_alphequ(size_t nb, char *base);
char			*ft_printfspecial(char *flag);
char			**ft_check_flags(char *str);
char			*ft_printfper(char *flag);
char			*ft_createbase(int nb);
char			*ft_which(char cflag);
void			ft_iszero(char *attribut, char *flag, char *str, char *which);
void			ft_replace_all(char **fill, char **flag);
void			ft_replacedel(char *flag, int start);
void			ft_delfchar(char *flag, int start);
void			ft_replace(char **flag, int y);
void			ft_init_struct(t_env *env);
size_t			ft_len(char *ret, ssize_t prelength, ssize_t length);
wchar_t			*ft_watt(wchar_t *ret, char *flag, int start, int length);
wchar_t			*ft_printfwchar(va_list *argv, char *flag);
wchar_t			*ft_printfwstr(va_list *argv, char *flag);
intmax_t		ft_changesize(char *flag, intmax_t vint);
uintmax_t		ft_changeusize(char *flag, uintmax_t vint);
uintmax_t		ft_find_pow(uintmax_t nb, uintmax_t base);
uintmax_t		ft_count_nb(uintmax_t nb);
uintmax_t		ft_nbequ(uintmax_t c);

/*
*** Fonction bonus
*/

char			*ft_printffloat(va_list *argv, char *flag);
char			*ft_printfbase(va_list *argv, char *flag);
char			*ft_printfbin(va_list *argv, char *flag);
int				ft_find_fd(char **fill, t_env *env, char *flag, va_list *argv);

int				ft_printf(const char *format, ...);

#endif
