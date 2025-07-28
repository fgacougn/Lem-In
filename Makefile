NAME=lem-in

SOURCES = \
algo/add_nodes.c\
algo/ants_ways.c\
algo/floodfill.c\
algo/parcours_floodfill.c\
algo/parcours_graphe.c\
algo/graph_simplify.c\
graph/t_way.c\
graph/t_arrete.c\
main.c\
graph/graph_utils.c\
parsing/parsing.c

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
