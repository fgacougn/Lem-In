#include "algo.h"

static char build_way_recursif_arrete(t_graphe_racine *terre, t_way * way,t_arrete *arrete, int index){
    int min = 0, is_back = 0;
    t_arrete *temp,*temp2 = 0;
    t_graphe_noeud *toreturn;

    way_print(way);
    ft_printf("\n");
    temp = arrete;
    do{
        ft_printf("ledo %d\n", index);
        if(is_back)
        {
            way_clearback(way);
        }
        temp = way->last->link->arretes;
        min = terre->size;
        toreturn = 0;
        is_back = 0;
        while (temp)
        {
            ft_printf("%s min: %d poid: %d has a way: %d seen: %d \n",temp->link->name,min,temp->link->poids,temp->link->has_a_way,temp->link->seen);
            
            if(min >= temp->link->poids && temp->link->has_a_way == FALSE && temp->link->seen == FALSE)
            {
                
                min = temp->link->poids;
                toreturn = temp->link;
                temp2 = temp;
            }
            
            temp = temp->next;
        }
        
        if(toreturn)
        {
            toreturn->seen = TRUE;
            if(way_addback(way, arrete_cpy(temp2))!= SUCCESS)
                    return ERR_MALLOC;
            way_print(way);
            ft_printf("\n");
        }
        is_back = 1;
    }while (toreturn != terre->end && toreturn && build_way_recursif_arrete(terre,way, toreturn->arretes, index + 1) == FAILURE);

    if(toreturn)
        return (SUCCESS);
    return(FAILURE);
}

char parcours_floodfill_arrete(t_graphe_racine *terre)
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
        ft_printf("retour vers avant %d\n", i);
        new = way_new(terre->size);
        // new->the_way[0] = terre->start;
        if(way_addback(new, arrete_new(terre->start)) == FAILURE)
            return (FAILURE);
        // if(build_way(terre, new) == SUCCESS)
        if(build_way_recursif_arrete(terre,new, new->arretes->link->arretes, 0) == SUCCESS)
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