#include "graph.h"

static int id_noeud = 0;

t_graphe_noeud *gnoeud_new(char *name, int x, int y)
{
    t_graphe_noeud *new;

    new = malloc(sizeof(t_graphe_noeud));
    if (new)
    {
        ft_bzero(new,sizeof(t_graphe_noeud));
        new->id = id_noeud++;
        new->name = name;
        new->is_peculiar = PECULIAR_NO;
        new->x = x;
        new->y = y;
        new->seen = 0;
        new->has_a_way = 0;
    }
    return(new);
}

void gnoeud_add_link(t_graphe_noeud *first, t_graphe_noeud *second)
{
    if (first && second)
    {
        int i;

        i = 0;
        while (first->links[i])
            i++;
        first->links[i] = second;
        first->links[++i] = NULL;
        i = 0;
        while (second->links[i])
            i++;
        second->links[i] = first;
        first->links[++i] = NULL;
        return (0);
    }
}


void gnoeud_del(t_graphe_noeud *del)
{
    free(del->links);
    free(del);
}

t_graphe_racine * gracine_new(void)
{
    t_graphe_racine *new;

    new = malloc(sizeof(t_graphe_racine));
    if (new)
    {
        ft_bzero(new, sizeof(t_graphe_racine));
        new->size = 0;
    }
}

void gracine_add_noeud(t_graphe_racine *dest, t_graphe_noeud *add)
{
    if (dest && add)
    {
        int i;

        i = 0;
        while (dest->all[i])
            i++;
        dest->all[i] = add;
        dest->all[++i] = NULL;
    }
}

void gracine_del(t_graphe_racine *target)
{
    free(target->all);
}

void gracine_clear(t_graphe_racine *target)
{
    for (int i = 0; i < target->size; i++)
        gnoeud_del(target->all[i]);
    gracine_del(target);
    free(target);
}


t_graphe_noeud *find_gnoued(t_list *lst, char *name)
{
    if(lst && name) 
    {
        t_graphe_noeud * noeud = (t_graphe_noeud *)lst->content;
        if(noeud->name == name)
            return (noeud);
        find_gnoued(lst->next,name);
    }
    return (NULL);
}