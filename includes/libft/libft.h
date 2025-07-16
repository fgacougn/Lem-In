/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: fgacougn <fgacougn@student.42.fr>          +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2023/12/28 16:07:05 by fgacougn          #+#    #+#             */
/*   Updated: 2023/12/28 16:07:05 by fgacougn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define OPTIONS "-0.# +123456789"
# define NB_OPTIONS 15
# define TYPES "cspndiuxX%"
# define NB_TYPES 9
# define SMOL 1
# define BIGOLD 2

# define ERR_BAD_READ -1
# define ERR_NUL_STR -2
# define SUCCESS -3
# define ERR_OVERFLOW -4
# define ERR_MALLOC -5
# define ERR_DOUBLON -6
# define ERR_BAD_MOVE -7
# define NEXT_MOVE -8
# define SUCCESS_CHILD -9
# define ERR_BAD_PNTR -10
# define FAILURE -11
# define ERR_BAD_FILE -12
# define ERR_BAD_NAME -13
# define ERR_BAD_ARGS -14
# define ERR_EMPTY -15
# define ERR_FULL -16
# define ERR_MLX -17
# define ERR_PARS -18
# define ERR_FORK -19
# define ERR_DUP -20
# define ERR_PIPE -21
# define ERR_BAD_DIR -22
# define ERR_UB -23
# define ERR_SIGNAL -24

# define WHITESPACES " \t\n\v\f\r"
# define GREYSPACES " \t\v\f\r"
# define ALPN "0123456789AaBbCcDdEeFfGgHhIiJjKklLMmNnOoPpQqRrSsTtUuVvWwXxYyZz"

# define ENVP_PATH 0
# define ENVP_PWD 1
# define ENVP_SIZE 2

# include <errno.h>
# include <fcntl.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

int						ft_isalpha(int c);
int						ft_isdigit(int c);
int						ft_isalnum(int c);
int						ft_isascii(int c);
int						ft_isprint(int c);
size_t					ft_strlen(const char *s);
void					*ft_memset(void *s, int c, size_t n);
void					ft_bzero(void *s, size_t n);
void					*ft_memcpy(void *dest, const void *src, size_t n);

char					*ft_substr(char const *s, unsigned int start,
							size_t len);
char					*ft_strjoin(char const *s1, char const *s2);
char					*ft_strtrim(char const *s1, char const *set);
char					**ft_split(char const *s, char c);
char					*ft_strdup(const char *s);
char					*ft_strndup(const char *s, int len);
char					*ft_itoa(int n);
char					*ft_strmapi(char const *s,
							char (*f)(unsigned int, char));
void					ft_striteri(char *s, void (*f)(unsigned int, char *));
void					ft_putchar_fd(char c, int fd);

void					ft_putstr_fd(char *s, int fd);
void					ft_putendl_fd(char *s, int fd);
void					ft_putnbr_fd(int n, int fd);
void					*ft_memmove(void *dest, const void *src, size_t n);
size_t					ft_strlcpy(char *dst, const char *src, size_t size);
size_t					ft_strlcat(char *dst, const char *src, size_t size);
int						ft_toupper(int c);
int						ft_tolower(int c);
char					*ft_strchr(const char *s, int c);

char					*ft_strrchr(const char *s, int c);
int						ft_strncmp(const char *s1, const char *s2, size_t n);
void					*ft_memchr(const void *s, int c, size_t n);
int						ft_memcmp(const void *s1, const void *s2, size_t n);
char					*ft_strnstr(const char *big, const char *little,
							size_t len);
int						ft_atoi(const char *nptr);
void					*ft_calloc(size_t nmemb, size_t size);
t_list					*ft_lstnew(void *content);
void					ft_lstadd_front(t_list **lst, t_list *new);

int						ft_lstsize(t_list *lst);
t_list					*ft_lstlast(t_list *lst);
void					ft_lstadd_back(t_list **lst, t_list *new);
void					ft_lstdelone(t_list *lst, void (*del)(void *));
void					ft_lstclear(t_list **lst, void (*del)(void *));
void					ft_lstiter(t_list *lst, void (*f)(void *));
t_list					*ft_lstmap(t_list *lst, void *(*f)(void *),
							void (*d)(void *));

char					*ft_getstr_printf(char ft, int *op, va_list *argp,
							int *nb_cr);
int						ft_printf(const char *format, ...);
char					*ft_get_empty(char *retour);
int						ft_is_in(char *charset, char c);
long long int			ft_llatoi(const char *nptr);
unsigned long long int	ft_ullatoi(const char *nptr);
void					ft_puterror(char *s);
int						ft_abs(int i);
double					ft_fabs(double i);
char					*get_next_line(int fd);
void					ft_free_split(char **split);

int						ft_str_startwith(char *insearch, char *tosearch);
char					**ft_get_envp(char **envp);
char					*ft_str_ijoin(char *start, char *intersec, char *end);
double					ft_datoi(const char *nptr);
int						ft_imax(int a, int b);
int						ft_imin(int a, int b);
float					ft_fmin(float a, float b);
int						ft_irel(int a);
int						ft_iid(int a);
double					ft_dmax(double a, double b);
double					ft_dmin(double a, double b);

char					**ft_splitcpy(char **split);
char					**ft_splitcpy_plus(char **split, char *stradd);
char					**ft_splitcpy_minus(char **split, char *strminus);
void					ft_printf_split(char **split);
void					ft_prefixe_printf_split(char **split, char *prefixe);
char					*ft_strbuild(char *str1, char *str2, char *str3,
							char *str4);
int						ft_is_insplit(char **charset, char *c);
char					*ft_hach_find(char *tofind, char **hach_map);
char					*ft_strtruetrim(char const *s1, char const *set);
char					*ft_quote_protection(char *str);
int						ft_split_cpt(char **split);

int						ft_strcmp(const char *s1, const char *s2);
int						ft_has_in(char *charset, char *str);
char					**ft_split_protected(char const *s, char c);
int						ft_bash_sort(const char *str1, const char *str2);

void					ft_split_sort(char **split, int (*cmp)(const char *,
								const char *));
int						ft_splitlen(char **split);
char					*ft_split_join(char **split);

#endif
