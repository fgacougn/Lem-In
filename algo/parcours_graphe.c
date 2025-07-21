#include "algo.h"

// algo
// |while length < max graph size / 2 + 1 or no more node/way added
// || all ways from start + 1
// || all ways from end + 1
char parcours_graphe(t_graphe_racine *terre)
{
    t_way **end;
    if(terre->start_ways)
        ways_del(terre->start_ways,terre->size);
    terre->start_ways = malloc((terre->size /2 + 1) * sizeof(t_way *));
    if(!terre->start_ways)
        return ERR_MALLOC;
    ft_bzero(terre->start_ways,(terre->size /2 + 1) * sizeof(t_way *));
    terre->start_ways[0] = way_new(terre->size);
    if(!terre->start_ways[0])
        return ERR_MALLOC;
    terre->start_ways[0]->the_way[0] = terre->start;
    terre->start->seen = PECULIAR_START;
    terre->start->has_a_way = TRUE;
    terre->start->first = terre->start_ways[0];
    gracine_print(terre);
    end = malloc((terre->size /2 + 1) * sizeof(t_way *));
    if(!end)
        return ERR_MALLOC;
    ft_bzero(end, (terre->size /2 + 1) * sizeof(t_way *));
    end[0] = way_new(terre->size);
    if(!end[0])
        return ERR_MALLOC;
    end[0]->the_way[0] = terre->end;
    terre->end->seen = PECULIAR_END;
    terre->end->has_a_way = TRUE;
    terre->end->first = end[0];
    int i = 0;
    int nb_nodes_e = 1, nb_nodes_s = 1;
    while ( i < terre->size / 2 + 1 && (nb_nodes_e || nb_nodes_s))
    {
        nb_nodes_s = add_nodes(terre->start_ways, STARTFROM_START);
        // nb_nodes_e = add_nodes(end, STARTFROM_END);

        gracine_print(terre);
        ft_printf("end\n");
        int j = 0;
        while(end[j])
        {
            if(end[j])
                way_print(end[j]);
            j++;
        }
        i++;
    }
    ways_del(end, terre->size /2 + 1);
    return SUCCESS;
}