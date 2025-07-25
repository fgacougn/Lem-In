#include "graph.h"

t_arrete *arrete_new( t_graphe_noeud *to)
{
    t_arrete *new = malloc(sizeof(t_arrete));
    if(new)
    {
        ft_bzero(new, sizeof(t_arrete));
        new->link = to;
        new->poids = 1;
        new->is_direct = TRUE;
    }
    return new;
}

t_arrete *arrete_new_large(t_graphe_noeud *from, t_graphe_noeud *from2, t_graphe_noeud *to, t_graphe_noeud *to2)
{
    // int poids = 2;
    if(from2 != to2)
    {
        t_graphe_noeud *temp_from = from, *temp_to = to;
        temp_from = temp_to;
    }
    return 0;
}
void arrete_del(t_arrete *target)
{
    if(target)
    {
        if(target->inside)
            free(target->inside);
        free(target);
    }
}
void arrete_clear(t_arrete *target)
{
    if(target)
    {
        arrete_clear(target->next);
        arrete_del(target);
    }
}

int arrete_len(t_arrete *target)
{
    if(target)
        return(1 + arrete_len(target->next));
    return 0;
}

int arrete_add_front(t_arrete **front, t_arrete *target)
{
    if(!front || !target)
        return FAILURE;
    if(!*front)
        *front = target;
    else
    {
        target->next = *front;
        *front = target;
    }
    return SUCCESS;
}

int arrete_pop(t_arrete **front, t_arrete *target)
{
    t_arrete *temp;
    if(!front || !*front)
        return FAILURE;
    temp = *front;
    if(temp == target)
    {
        *front = temp->next;
        return SUCCESS;
    }
    while(temp && temp->next != target)
        temp = temp->next;
    if(!temp)
        return FAILURE;
    temp->next = target->next;
    return SUCCESS;
}

void print_arretes(t_arrete *target)
{
    if(target)
    {
        ft_printf("%s/", target->link->name);
        print_arretes(target->next);
    }
}