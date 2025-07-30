#include "algo.h"

static char is_possible_way(t_arrete *link, int seen_value, int min)
{
    // ft_printf("%s %d: start? %d//", link->link->name, link, link->link->is_peculiar != PECULIAR_START);
    // ft_printf("seen %d,seen_value %d, %d//",link->link->seen,  seen_value, link->link->seen < seen_value);
    // ft_printf("min %d, poids %d, %d//", min, link->link->poids, min >= link->link->poids);
    // ft_printf("way %d true? %d\n",link->has_a_way , link->linkedto->has_a_way != WAY_TRUE);
    return 
    link->link->is_peculiar != PECULIAR_START && link->link->seen < seen_value &&  min >= link->link->poids && link->has_a_way != WAY_TRUE;
} ;

static char build_way_recursif(t_graphe_racine *terre, t_way * way,t_arrete *arrete, int index, char going_back){
    int min = 0, is_back = 0, nextIndex = index, nextBack = going_back;
    t_arrete *temp,*temp2 = 0;
    t_graphe_noeud *toreturn;

    // way_print(way);
    // ft_printf("\n");
    temp = arrete;
    do{
        // ft_printf("ledo %d\n", index);
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
            // ft_printf("%s min: %d poid: %d has a way: %d seen: %d , // %d\n",temp->link->name,min,temp->link->poids,temp->link->has_a_way,temp->link->seen, is_possible_way(temp,index, min));
            
            if(is_possible_way(temp,index, min))
            {
                if(temp->has_a_way == WAY_REVERSABLE)
                {
                    nextBack = TRUE;
                    if(going_back == nextBack )
                    {
                        // nextIndex = index + 1;
                    }
                }
                else
                {
                    nextBack = FALSE;
                    nextIndex = index;
                }
                min = temp->link->poids;
                toreturn = temp->link;
                temp2 = temp;
            }
            
            temp = temp->next;
        }
        
        if(toreturn)
        {
            toreturn->seen = nextIndex;
            temp2->seen = nextIndex;
            if(way_addback(way, arrete_cpy(temp2))!= SUCCESS)
                    return ERR_MALLOC;
            // way_print(way);
            // ft_printf("\n");
        }
        is_back = 1;
    }while (toreturn != terre->end && toreturn && build_way_recursif(terre,way, toreturn->arretes, nextIndex, nextBack) == FAILURE);

    if(toreturn)
        return (SUCCESS);
    return(FAILURE);
}

char parcours_edmonds_karps(t_graphe_racine *terre)
{
    if(terre->end->poids == -1)
        return FAILURE;
    if(terre->ek_ways)
        ways_del(terre->ek_ways,terre->size);
    terre->ek_ways = malloc((terre->size /2 + 1) * sizeof(t_way *));
    if(!terre->ek_ways)
        return ERR_MALLOC;
    ft_bzero(terre->ek_ways,(terre->size /2 + 1) * sizeof(t_way *));
    terre->start->has_a_way = TRUE;
    int i = -1;
    t_way * new;

    gracine_clean_seen(terre);
    do
    {
        i++;
        // ft_printf("ekretour vers avant %d\n", i);
        new = way_new(terre->size);
        // new->the_way[0] = terre->start;
        if(way_addback(new, arrete_new(terre->start)) == FAILURE)
            return (FAILURE);
        // if(build_way(terre, new) == SUCCESS)
        if(build_way_recursif(terre,new, new->arretes->link->arretes, 1, 0) == SUCCESS)
        {
            terre->ek_ways[i] = new;
            // gracine_count_ways_arretes(terre);
            set_way(new);
            // gracine_count_ways_arretes(terre);
        }
        else
            way_del(new);
        gracine_clean_seen(terre);
    }while (terre->ek_ways[i]);
    sort_ways(terre->ek_ways);
    if(terre->ek_ways[0])
        return SUCCESS;
    return FAILURE;
}