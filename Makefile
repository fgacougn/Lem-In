NAME=lem-in

SOURCES = \
algo/add_nodes.c\
algo/ants_ways.c\
algo/floodfill.c\
algo/parcours_floodfill.c\
algo/parcours_graphe.c\
graph/t_way.c\
main.c\
graph/graph_utils.c\
parsing/parsing.c

$(NAME) :
	make -C ./includes/libft
	cc -Wall -Werror -Wextra -g3 $(SOURCES) -L./includes -lft -I./includes -o $(NAME)

clean : 
	 make clean -C includes/libft
	 
fclean :
	 make fclean -C includes/libft
	 rm -f $(NAME)

re : fclean $(NAME)

.PHONY : clean fclean re
