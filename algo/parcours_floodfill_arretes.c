#include "algo.h"

static char build_way_recursif(t_graphe_racine *terre, t_way * way, int index)
{
    int min, i;
    t_graphe_noeud *toreturn;
    do {
        way->the_way[index + 1] = 0;
        min = terre->size;
        i = 0;
        toreturn = 0;
        do{
            // ft_printf("%d %d %d %d %d %d ", index, i,way->the_way[index], way->the_way[index]->links[i]->poids, way->the_way[index]->links[i]->has_a_way, way->the_way[index]->links[i]->seen);
            // ft_printf("%s\n", way->the_way[index]->links[i]->name);
            if(min >= way->the_way[index]->links[i]->poids && way->the_way[index]->links[i]->has_a_way == FALSE && way->the_way[index]->links[i]->seen == FALSE)
            {
                min = way->the_way[index]->links[i]->poids;
                toreturn = way->the_way[index]->links[i];
            }
            i++;
        }while(way->the_way[index]->links[i]);
        // if(toreturn)
        //     ft_printf("//%d %s\n", index, toreturn->name);
        way->the_way[index + 1] = toreturn;
        if(toreturn)
            toreturn->seen = TRUE;
    } while(toreturn != terre->end && toreturn && build_way_recursif(terre, way, index + 1) == FAILURE);
    if(toreturn)
        return SUCCESS;
    return FAILURE;
    
}

char parcours_floodfill_arretes(t_graphe_racine *terre)
{
    if(terre->end->poids == -1)
        return FAILURE;
    if(terre->start_ways)
        ways_del(terre->start_ways,terre->size);
    terre->start_ways = malloc((terre->size /2 + 1) * sizeof(t_way *));
    if(!terre->start_ways)
        return ERR_MALLOC;
    ft_bzero(terre->start_ways,(terre->size /2 + 1) * sizeof(t_way *));
    terre->start->has_a_way = TRUE;
    int i = -1;
    t_way * new;
    do
    {
        i++;
        new = way_new(terre->size);
        new->the_way[0] = terre->start;
        // if(build_way(terre, new) == SUCCESS)
        if(build_way_recursif(terre, new, 0) == SUCCESS)
        {
            terre->start_ways[i] = new;
            set_way(new);
        }
        else
            path_clear(new);
        gracine_clean_seen(terre);
    }while (terre->start_ways[i]);
    sort_ways(terre->start_ways);
    if(terre->start_ways[0])
        return SUCCESS;
    return FAILURE;
}