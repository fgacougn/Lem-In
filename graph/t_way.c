#include "graph.h"

t_way * way_new(int size)
{
    t_way *new;
    new = malloc(sizeof(t_way));
    if(new)
    {
        new->the_way = malloc(size * sizeof(t_graphe_noeud));
        if(new->the_way)
        {
            new->size = size;
            ft_bzero(new->the_way, size * sizeof(t_graphe_noeud))
            return new;
        }
        free(new);
    }
    return new;
}

void way_del(t_way *todel)
{
    if(!todel)
        return;
    free(todel->the_way);
    free(todel);
}

void ways_del(t_way** todel, int size )
{
    if(!todel)
        return;
    for(int i = 0; i< size; i++)
        if(todel[i])
            way_del(todel[i]);
}

t_way *way_cpy(t_way *tocpy)
{
    new = way_new(tocpy->size);
    int i = 0;
    while(tocpy->the_way[i])
        new->the_way[i] = tocpy->the_way[i];
    return new;
}

void way_add(t_way *start, t_way *end)
{
    int i = -1; j = -1;
    while(start->the_way[++i]);
    while(end->the_way[++j])
        start->the_way[i + j + 1] = end->the_way[j];
}