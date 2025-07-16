CC=cc
CFLAGS=-Wall -Werror -Wextra -g3
SOURCES=ft_add_dieze.c ft_get_bigoldhexa.c ft_get_space.c ft_get_zero_z.c ft_isprint.c ft_lstclear_bonus.c ft_lstsize_bonus.c ft_pitoa.c \
ft_setint.c ft_strlcat.c ft_strrchr.c ft_add_sign.c ft_get_ecaps.c ft_get_str.c ft_isalnum.c ft_itoa.c ft_lstdelone_bonus.c ft_memchr.c\
ft_printf.c ft_split.c ft_strlcpy.c ft_strtrim.c ft_atoi.c ft_get_empty.c ft_getstr_printf.c ft_isalpha.c ft_itohexbigold.c ft_lstiter_bonus.c\
ft_memcmp.c ft_putchar_fd.c ft_strchr.c ft_strlen.c ft_substr.c ft_bzero.c ft_getint.c ft_get_str_zeros.c ft_isascii.c ft_itohexsmol.c\
ft_lstlast_bonus.c ft_memcpy.c ft_putendl_fd.c ft_strdup.c ft_strmapi.c ft_tolower.c ft_getpointeur.c ft_getunsignedint.c ft_isdigit.c\
ft_lstadd_back_bonus.c ft_lstmap_bonus.c ft_memmove.c ft_putnbr_fd.c ft_striteri.c ft_strncmp.c ft_toupper.c ft_calloc.c ft_get_smolhexa.c\
ft_get_zeros.c ft_is_in.c ft_lstadd_front_bonus.c ft_lstnew_bonus.c ft_memset.c ft_putstr_fd.c ft_strjoin.c ft_strnstr.c ft_uitoa.c\
ft_llatoi.c ft_puterror.c ft_abs.c get_next_line.c get_next_line_utils.c ft_str_startwith.c ft_get_envp.c ft_str_ijoin.c ft_fabs.c\
ft_datoi.c ft_imax.c ft_fmin.c ft_imin.c ft_irel.c ft_iid.c ft_dmin.c ft_dmax.c ft_printf_split.c ft_splitcpy.c ft_splitcpy_plus.c\
ft_splitcpy_minus.c ft_strbuild.c ft_is_insplit.c ft_strndup.c ft_hach_find.c ft_strtruetrim.c ft_split_cpt.c ft_strcmp.c\
ft_has_in.c ft_split_protected.c ft_bash_sort.c ft_split_sort.c ft_splitlen.c ft_split_join.c ft_ullatoi.c\
ft_quote_protection.c ft_prefixe_printf_split.c
CIBLES=$(SOURCES:.c=.o)
NAME=libft.a

%.o: %.c  libft.h
	$(CC) -o $@ -c $< $(CFLAGS)


all: $(CIBLES) $(NAME)

$(NAME): libft.h $(CIBLES)
	ar rcs $(NAME) libft.h $(CIBLES_B) $(CIBLES)

bonus: $(CIBLES_B) $(CIBLES)
	ar r $(NAME) libft.h $(CIBLES_B) $(CIBLES)

clean:
	rm -f $(CIBLES) $(CIBLES_B) libft.so

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean