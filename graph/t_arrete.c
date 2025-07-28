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

void next_arrete(t_graphe_noeud **from, t_graphe_noeud **before)
{
    if((*from)->arretes->link == *before)
    {
        *before = *from;
        *from = (*from)->arretes->next->link;
    }
    else
    {
        *before = *from;
        *from = (*from)->arretes->link;
    }
}

static int build_large(t_arrete *target, int size)
{
    target->poids = size;
    target->is_direct = FALSE;
    target->inside = malloc(size * sizeof(t_graphe_noeud *));
    if(!target->inside)
        return ERR_MALLOC;
    ft_bzero(target->inside, size * sizeof(t_graphe_noeud *));
    return SUCCESS;
}

int arrete_new_large(t_graphe_noeud *from, t_graphe_noeud *from2, t_graphe_noeud *to, t_graphe_noeud *to2)
{
    // ft_printf("Pop? %s %s\n", from->name, to->name);
    int poids = 1;
    t_graphe_noeud *temp0, *temp1;
    temp0 = from, temp1 = from2;
    while(temp1 != to)
    {
        poids++;
        next_arrete(&temp1, &temp0);
    }
    t_arrete *arretef, *arretet;
    arretef = from->arretes;
    arretet = to->arretes;
    while(arretef->link != from2)
        arretef = arretef->next;
    while(arretet->link != to2)
        arretet = arretet->next;
    if(build_large(arretef, poids) != SUCCESS)
        return ERR_MALLOC;
    if(build_large(arretet, poids) != SUCCESS)
        return ERR_MALLOC;
    arretet->inside[poids - 1] = from;
    // ft_printf("%s/", from->name);
    arretef->link = to;
    arretet->link = from;
    for(int i = 0; i < poids ; i++)
    {
        // ft_printf("%s/", from2->name);
        arretef->inside[i] = from2;
        if(poids - 2 -i >= 0)
            arretet->inside[poids - 2 -i] = from2;
        if(from2 != to)
            next_arrete(&from2, &from);
    }
    // ft_printf("\narretef");
    for(int i = 0; i < poids - 1; i++)
    {
        arretef->inside[i]->has_a_way = TRUE;
        // ft_printf("%s/", arretef->inside[i]->name);
    }
    // for(int i = 0; i < poids; i++)
    // {
    //     // arretef->inside[i]->has_a_way = TRUE;
    //     ft_printf("%s/", arretef->inside[i]->name);
    // }
    // ft_printf("\narretet");
    // for(int i = 0; i < poids; i++)
    // {
    //     ft_printf("%s/", arretet->inside[i]->name);
    // }
    
    // ft_printf("///%s\n",from->name);
    return SUCCESS;
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