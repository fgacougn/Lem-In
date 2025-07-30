#ifndef PARSING_H
# define PARSING_H

# include "algo.h"

int get_room(char *line, char is_peculiar, t_graphe_racine *rac, t_list **liste);
int get_end_start(char **line, t_graphe_racine *rac, char * is_peculiar);
int get_links(t_list **noeud, char *line);
int malloc_links(t_list *list, int size);
int check_tab(char **tab);
int get_ants(char *line);
t_graphe_racine *parsing();
void fill_racine(t_graphe_racine *racine, t_list * liste);

#endif