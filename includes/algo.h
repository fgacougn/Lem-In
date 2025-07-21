#ifndef ALGO_H
# define ALGO_H

#include "graph.h"
#define STARTFROM_END PECULIAR_END
#define STARTFROM_START PECULIAR_START

char parcours_graphe(t_graphe_racine *);
int add_nodes(t_way **ways_to_add_nodes, char start);

#endif