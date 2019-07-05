/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clonger <clonger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 17:58:08 by clonger           #+#    #+#             */
/*   Updated: 2019/06/11 15:58:04 by clonger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <strings.h>
# include <stdlib.h>
# include <ctype.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/uio.h>
# include <sys/types.h>
# include <fcntl.h>
# include <wchar.h>
# include <locale.h>
# include <limits.h>
# include <stdint.h>

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

int				ft_strinbase(char *str, char *base, int start, int length);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
int				ft_isempty(char *str, size_t start, size_t length);
int				ft_charnchr(const char *str, int start, int c);
int				ft_strequ(char const *s1, char const *s2);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_charchr(const char *str, int c);
int				ft_operand(int argc, char **argv);
int				ft_only_number(const char *str);
int				ft_is_int(intmax_t n, int neg);
int				ft_is_tab_number(char **tab);
int				ft_countnb(intmax_t n);
int				ft_isspace(char c);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
int				ft_islower(int c);
int				ft_isupper(int c);
char			*ft_addncharfree(char *s, char c, int length, double option);
char			*ft_strjoinfree(char const *s1, char const *s2, int option);
char			*ft_delnchar(const char *s, int c, int start, int length);
char			*ft_addnchar(char *source, int start, char c, int length);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strmapi(char const *s, char(*f)(unsigned int, char));
char			*ft_strnstr(const char *s1, const char *s2, size_t len);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strncpy(char *dest, const char *src, size_t n);
char			*ft_strcatsub(char *s1, char *s2, char rep, int i);
char			*ft_strncat(char *s1, const char *s2, size_t n);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_ftoa(long double n, size_t precision);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_strcat(char *dest, const char *src);
char			*ft_tab_to_str(char **tab, char *space);
char			**ft_strsplit(char const *s, char c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strchr(const char *s, int c);
char			**ft_tabdup(const char **tab);
char			*ft_wstrtostr(wchar_t *wstr);
char			*ft_strtrim(char const *s);
char			*ft_strdup(const char *s);
char			*ft_strnew(size_t size);
char			*ft_utoa(uintmax_t n);
char			*ft_itoa(intmax_t n);
char			*ft_strrev(char *s);
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			*ft_memccpy(void *dst, const void *rc, int c, size_t n);
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
void			ft_putnullstr_fd(char const *str, char *flag, int fd);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			ft_vdelnchar(char *s, int c, int start, int length);
void			ft_print_params_fd(int argc, char **argv, int fd);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			ft_sort_params_fd(int argc, char **argv, int fd);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void			ft_putcstr(char const *str, int c, int start);
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_memset(void *b, int c, size_t len);
void			ft_striter(char *s, void (*f)(char *));
void			ft_strcut(char *str, int start, int c);
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putwchar_fd(wchar_t wchr, int fd);
void			ft_putwstr_fd(wchar_t *wstr, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putchar_fd(char c, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_bzero(void *s, size_t n);
void			ft_putwchar(wchar_t wchr);
void			ft_putwstr(wchar_t *wstr);
void			*ft_memalloc(size_t size);
void			ft_putendl(char const *s);
void			ft_putstr(char const *s);
void			ft_puttabendl(char **s);
void			ft_tabdel(char **tab);
void			ft_tabrev(char **tab);
void			ft_memdel(void **ap);
void			ft_strdel(char **as);
void			ft_puttab(char **s);
void			ft_strclr(char *s);
void			ft_putchar(char c);
void			ft_putnbr(int n);
double			ft_pow(double nb, double power);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
size_t			ft_count_char(const char *str, char c, int start);
size_t			ft_wstrlen(wchar_t *wstr, const char *option);
size_t			ft_find_prime(size_t nb, const char *which);
size_t			ft_count_word(const char *str);
size_t			ft_tablen(const char **tab);
size_t			ft_strlen(const char *s);
size_t			ft_wchrlen(wchar_t wchr);
t_list			*ft_lstnew(void const *content, size_t content_size);
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
wchar_t			*ft_wstrsub(wchar_t const *ws, unsigned int start, size_t len);
wchar_t			*ft_addnwchar(wchar_t *str, int start, wchar_t c, int length);
wchar_t			*ft_wstrdup(const wchar_t *ws);
intmax_t		ft_atoi(const char *str);
uintmax_t		ft_atou(const char *str);
int				get_next_line(const int fd, char **line);

#endif
