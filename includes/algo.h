#ifndef ALGO_H
# define ALGO_H

#include "graph.h"
#define STARTFROM_END PECULIAR_END
#define STARTFROM_START PECULIAR_START

#define WALKING_SIZE 5
#define WALKING_FIRST 0
#define WALKING_NB 1
#define WALKING_FIRST_ROOM 2
#define WALKING_LNB 3
#define WALKING_END 4

char parcours_graphe(t_graphe_racine *);
int add_nodes(t_way **ways_to_add_nodes, char start);
void floodfill(t_graphe_racine *);
void floodfill_arretes(t_graphe_racine *);
char parcours_floodfill(t_graphe_racine *);
char parcours_floodfill_arrete(t_graphe_racine *terre);
char parcours_edmonds_karps(t_graphe_racine *);
void ants_ways(t_graphe_racine *);
int graph_simplify(t_graphe_racine *);

#endif