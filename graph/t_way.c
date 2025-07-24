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
            ft_bzero(new->the_way, size * sizeof(t_graphe_noeud));
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
    free(todel);
}

t_way *way_cpy(t_way *tocpy)
{
    t_way *new = way_new(tocpy->size);
    int i = -1;
    while(tocpy->the_way[++i])
        new->the_way[i] = tocpy->the_way[i];
    // i+=1;
    ft_printf("iondex cpy %d\n", i);
    if(--i >=0)
        new->the_way[i] = 0;
    ft_printf("copy:\n");
    way_print(tocpy);
    way_print(new);
    return new;
}


void way_print(t_way *target)
{
    int i = 0;
    while(target->the_way[i])
    {
        ft_printf("->%s", target->the_way[i]->name);
        i++;
    }
    ft_printf("\n");
}

void way_add(t_way *start, t_way *end)
{
    int i = -1;
    while(start->the_way[++i]);
    int j = -1;
    while(end->the_way[++j]);
    ft_printf("%d %d\n", end->the_way[0], j);
    way_print(end);
    while(--j + 1)
    {
        ft_printf("adding %d in %d\n",j , i);
        start->the_way[i++] = end->the_way[j];
    }
    
    // start->the_way[i] = end->the_way[0];
}

int way_len(t_way *target)
{
    int i =0;
    while(target->the_way[i])
        i++;
    return i;
}

void path_clear(t_way *target)
{
    int i = 1;
    while(target->the_way[i])
    {
        target->the_way[i]->has_a_way = FALSE;
        i++;
    }
    way_del(target);
}

void set_way(t_way *target)
{
    int i = 0;
    while(target->the_way[i])
    {
        if(target->the_way[i]->is_peculiar != PECULIAR_END)
            target->the_way[i]->has_a_way = TRUE;
        i++;
    }
}

void sort_ways(t_way **target)
{
    int hasmoved;
    t_way *temp;
    hasmoved = 1;
    while(hasmoved)
    {
        hasmoved = 0;
        for(int i = 0; i < id_noeud - 1 && target[i + 1]; i++)
        {
            if(way_len(target[i]) > way_len(target[i+1]))
            {
                hasmoved = 1;
                temp = target[i];
                target[i] = target[i+1];
                target[i+1] =temp;
            }
        }
    }
    
}