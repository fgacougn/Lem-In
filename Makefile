NAME=lem-in

SOURCES = \
algo/ants_ways.c\
algo/floodfill.c\
algo/parcours_edmonds_karps.c\
algo/graph_simplify.c\
graph/t_way.c\
graph/t_arrete.c\
main.c\
graph/graph_utils.c\
parsing/parsing.c\
algo/parcours_floodfill_arretes.c\



$(NAME) : $(SOURCES)
	make -C ./includes/libft
	mv ./includes/libft/libft.a ./includes/.
	cc -Wall -Werror -Wextra -g3 $(SOURCES) -L./includes -lft -I./includes -o $(NAME)

clean : 
	make clean -C includes/libft
	 
fclean :
	 make fclean -C includes/libft
	 rm -f $(NAME)
	 rm -f ./includes/libft.a

re : fclean $(NAME)

.PHONY : clean fclean re
