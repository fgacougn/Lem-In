#include "algo.h"

t_graphe_noeud *get_next_min(t_graphe_noeud *target, int max)
{
    int min = max, i = 0;
    t_graphe_noeud *toreturn = 0;
    do{
        if(min >= target->links[i]->poids && target->links[i]->has_a_way == FALSE)
        {
            min = target->links[i]->poids;
            toreturn = target->links[i];
        }
        i++;
    }while(target->links[i]);
    return toreturn;
}

char build_way(t_graphe_racine *terre, t_way * way)
{
    int i = 0;
    t_graphe_noeud *next;
    do
    {
        next = get_next_min(way->the_way[i++], terre->size);
        if(next)
        {
            if(next != terre->end)
                next->has_a_way = TRUE;
            way->the_way[i] = next;
        }
    }
    while(next && next != terre->end);
    if(next == terre->end)
        return SUCCESS;
    return FAILURE;

}

char parcours_floodfill(t_graphe_racine *terre)
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
        if(build_way(terre, new) == SUCCESS)
            terre->start_ways[i] = new;
        else
            path_clear(new);
    }while (terre->start_ways[i]);
    if(terre->start_ways[0])
        return SUCCESS;
    return FAILURE;
}