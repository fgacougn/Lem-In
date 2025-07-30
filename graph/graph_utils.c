#include "graph.h"

int id_noeud = 0;

t_graphe_noeud *gnoeud_new(char *name, int x, int y)
{
    t_graphe_noeud *new;

    new = malloc(sizeof(t_graphe_noeud));
    if (new)
    {
        ft_bzero(new,sizeof(t_graphe_noeud));
        new->name = ft_strdup( name);
        if(!new->name){
            free(new);
            return 0;
        }
        new->id = id_noeud++;
        new->is_peculiar = PECULIAR_NO;
        new->x = x;
        new->y = y;
        new->seen = 0;
        new->has_a_way = 0;
        new->poids = -1;
    }
    return(new);
}

int gnoeud_add_link(t_graphe_noeud *first, t_graphe_noeud *second)
{
    if (first && second)
    {
        int i;

        i = 0;
        while (first->links[i])
        {
            if(first->links[i]->id == second->id)
                return(FAILURE);
            i++;
        }
        first->links[i] = second;
        i = 0;
        while (second->links[i])
            i++;
        second->links[i] = first;
        return (SUCCESS);
    }
    return (FAILURE);
}

int gnoeud_has_arrete(t_graphe_noeud *first, t_graphe_noeud *second)
{
    t_arrete *temp;
    if(!first || !second)
        return FALSE;
    temp = first->arretes;
    while(temp && temp->link != second)
        temp = temp->next;
    if(temp && temp->link == second)
        return TRUE;
    return FALSE;
}


int gnoeud_add_arrete(t_graphe_noeud *first, t_graphe_noeud *second)
{
    if(!first || !second || gnoeud_has_arrete(first, second) || gnoeud_has_arrete(second, first))
        return FAILURE;
    t_arrete *new, *new2;
    new = arrete_new(second);
    if(!new)
        return FAILURE;
    if(arrete_add_front(&(first->arretes), new) == FAILURE)
        return FAILURE;
    new2 = arrete_new(first);
    if(!new2)
        return FAILURE;
    if(arrete_add_front(&(second->arretes), new2) == FAILURE)
        return FAILURE;
    new->linkedto = new2;
    new2->linkedto = new;
    return SUCCESS;
}


void gnoeud_del(t_graphe_noeud *del)
{
    if(!del)
        return;
    if(del->name)
        free(del->name);
    if(del->links)
        free(del->links);
    if(del->links_up)
        free(del->links_up);
    if(del->links_down)
        free(del->links_down);
    if(del->arretes)
        arrete_clear(del->arretes);
    free(del);
}

void gnoeud_print(t_graphe_noeud *toprint)
{
    if(toprint)
    ft_printf("id=%d\n,name=/%s/\nlinks=%d\n,is_peculiar=%d,\nx=%d,\ny=%d\n,seen=%d\n,has_a_way=%d\n",
toprint->id,toprint->name,toprint->links,toprint->is_peculiar,toprint->x,toprint->y,toprint->seen,toprint->has_a_way);
    else ft_printf("Noeud innexistant\n");
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
    return new;
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
    // ft_printf("target %x\n", target);
    if(target->all)
        for (int i = 0; i < target->size; i++)
            gnoeud_del(target->all[i]);
    gracine_del(target);
    if(target->start_ways)
        ways_del(target->start_ways, target->size /2 + 1);
    if(target->ek_ways)
        ways_del(target->ek_ways, target->size /2 + 1);
    free(target);
}


t_graphe_noeud *find_gnoued(t_list *lst, char *name)
{
    if(lst && name) 
    {
        t_graphe_noeud * noeud = (t_graphe_noeud *)lst->content;
        if( !ft_strcmp( noeud->name,name))
            return (noeud);
        return find_gnoued(lst->next,name);
    }
    return (NULL);
}


void gracine_print(t_graphe_racine *target)
{
    ft_printf("start %s\n", target->start->name);
    ft_printf("end %s\n", target->end->name);
    int j;
    for (int i =0; i < target->size ; i++)
    {
        ft_printf("Noeud %d: %s seen %d poids %d links", i, target->all[i]->name, target->all[i]->seen, target->all[i]->poids);
        j = 0;
        while(target->all[i]->links[j])
        {
            ft_printf("%s/",target->all[i]->links[j]->name);
            j++;
        }
        ft_printf("arretes?");
        if(target->all[i]->arretes)
            print_arretes(target->all[i]->arretes);
        ft_printf("first %x", target->all[i]->first);
        ft_printf("\n");
    }
    int i;
    i = 0;
    if(target->start_ways)
        while(target->start_ways[i])
        {
            if(target->start_ways[i])
                way_print(target->start_ways[i]);
            i++;
        }
}

void gracine_clean_seen(t_graphe_racine *target)
{
    t_arrete *arretes;
    for(int i = 0 ; i < target->size ; i++ )
    {
        if(target->all[i]->poids != -1)
        {
            target->all[i]->seen = 0;
            arretes = target->all[i]->arretes;
            while(arretes)
            {
                arretes->seen = FALSE;
                arretes = arretes->next;
            }
        }
    }
}


void gracine_clean_way(t_graphe_racine *target)
{
    t_arrete *arretes;
    for(int i = 0 ; i < target->size ; i++ )
    {
        if(target->all[i]->poids != -1)
        {
            target->all[i]->has_a_way = 0;
            arretes = target->all[i]->arretes;
            while(arretes)
            {
                arretes->has_a_way = FALSE;
                arretes = arretes->next;
            }
        }
    }
}

int set_link_tabs(t_graphe_racine *racine)
{
    int j = 0;
    for(int i = 0 ; i < racine->size ; i++)
    {
        while(racine->all[i]->links[j])
            j++;
        racine->all[i]->links_up = malloc(sizeof(t_graphe_noeud * ) * (j+1));
        racine->all[i]->links_down = malloc(sizeof(t_graphe_noeud * ) * (j+1));
        if(!(racine->all[i]->links_up) || !(racine->all[i]->links_down))
            return ERR_MALLOC;
    }
    return SUCCESS;
}

int set_tab_way(t_way **way)
{
    int k, i = 0,size;
    t_arrete *temp;

    while (way[i])
    {
        temp = way[i]->arretes;
        size = count_noeud(temp);
        way[i]->the_way = malloc(sizeof(t_graphe_noeud *) * (size + 1));
        if(!way[i]->the_way)
            return(ERR_MALLOC);
        k = 0;
        while (temp)
        {
            if(temp->is_direct == TRUE)
            {
                way[i]->the_way[k] = temp->link;
                k++;
            }
            else for( int j = 0; j < temp->linkedto->poids ; j++)
            {
                way[i]->the_way[k] = temp->linkedto->inside[j];
                k++;
            }
            way[i]->the_way[k] = 0;
            temp = temp->next;
        }
        i++;
    }
    return(SUCCESS);
}