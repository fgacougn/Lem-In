NAME=lem-in

$(NAME) :
	make -C ./includes/libft
	cc -Wall -Werror -Wextra -g3 *.c */*.c */*/*.c -L./includes -lft -I./includes

../includes/exec.h :
	 make -C exec

../includes/minishell.h :
	 make -C kernel

../includes/u_parsing.h :
	 make -C u_parse

../includes/libft/libft.h :

clean : 
	 make clean -C includes/libft
	 make clean -C exec
	 make clean -C u_parse
	 make clean -C kernel
	 
fclean :
	 make fclean -C includes/libft
	 make fclean -C exec
	 make fclean -C u_parse
	 make fclean -C kernel
	 rm -f $(NAME)

test: $(NAME)
	clear ; cat /dev/random | valgrind ./minishell 

re : fclean $(NAME)

.PHONY : clean fclean
