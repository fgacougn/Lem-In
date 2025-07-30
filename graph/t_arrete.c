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
    while(arretef->link != from2 )
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
    arretef->linkedto = arretet;
    arretet->link = from;
    arretet->linkedto =arretef;
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
        ft_printf("%s+%d/", target->link->name, target->has_a_way,target->linkedto);
        print_arretes(target->next);
    }
}

t_arrete *arrete_cpy(t_arrete *tocpy)
{
    if (!tocpy)
        return(NULL);
    t_arrete *new = arrete_new(tocpy->link);
    if(new)
    {
        new->poids = tocpy->poids;
        new->is_direct = tocpy->is_direct;
        new->linkedto = tocpy;
    }
    return new;
}

// int arrete_way_length(t_arrete *target)
// {
//     while(target)
//     {
//         // ft_printf("%s,%d->", target->link->name,target->has_a_way);
//         if(target->has_a_way == WAY_REVERSABLE)
//             return 1 + arrete_way_length(target->link->arretes);
//         else return arrete_way_length(target->next);
//     }
//     return 0;
// }

int arrete_way_length(t_arrete *target)
{
    if(!target)
        return 0;
    int size = 1;
    while(target)
    {
        // ft_printf("%s,%d?", target->link->name, target->has_a_way);
        if(target->has_a_way==WAY_TRUE)
        {
            // ft_printf("%s %d//", target->link->name,size);
            target = target->link->arretes;
            size++;
        }
        else target = target->next;
    }
    return size;
}


// t_arrete * arrete_build_way(t_arrete **way_to_build, t_arrete *going_through)
// {
//     if(going_through && way_to_build)
//     {
//         if(going_through->has_a_way == WAY_REVERSABLE)
//         {
//             *way_to_build = arrete_cpy(going_through);
//             if(!(*way_to_build))
//                 return 0;
//             return arrete_build_way(&((*way_to_build)->next), going_through->link->arretes);
//         }
//         else if(going_through->next)
//             return arrete_build_way(way_to_build,  going_through->next);
//     }
//     return going_through;
// }


int arrete_build_way(t_way *way_to_build, t_arrete *going_through)
{
    if(!going_through || !way_to_build)
        return FAILURE;
    while(going_through)
    {
        // ft_printf("%s,%d?", going_through->link->name, going_through->has_a_way);
        if(going_through->has_a_way==WAY_TRUE)
        {
            // ft_printf("%s//", going_through->link->name);
            if(way_addback(way_to_build, arrete_cpy(going_through)) == FAILURE)
                return (FAILURE);
            going_through = going_through->link->arretes;
        }
        else
            going_through = going_through->next;
    }
    return SUCCESS;
}