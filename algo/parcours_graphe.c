#include "algo.h"

// algo
// |while length < max graph size / 2 + 1 or no more node/way added
// || all ways from start + 1
// || all ways from end + 1
char parcours_graphe(t_graphe_racine *terre)
{
    t_way **end;
    if(terre->start_ways)
        ways_del(terre->start_ways)
    terre->start_ways = malloc((terre->size /2 + 1) * sizeof(t_way *));
    if(!terre->start_ways)
        return ERR_MALLOC;
    terre->start_ways[0] = way_new(terre->size);
    if(!terre->start_ways[0])
        return ERR_MALLOC;
    terre->start_ways[0]->the_way[0] = terre->start;
    end = malloc((terre->size /2 + 1) * sizeof(t_way *));
    if(!end)
        return ERR_MALLOC;
    end[0] = way_new(terre->size);
    if(!end[0])
        return ERR_MALLOC;
    end->the_way[0] = terre->end;
    int i = 0;
    int nb_nodes_e = 1, nb_nodes_s = 1;
    while ( i < terre->size / 2 + 1 && (nb_nodes_e || nb_nodes_s))
    {
        nb_nodes_s = add_nodes(terre->start_ways, STARTFROM_START);
        nb_nodes_e = add_nodes(end, STARTFROM_END);
        i++;
    }
}