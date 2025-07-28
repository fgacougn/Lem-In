#include "algo.h"

int graph_simplify(t_graphe_racine *racine)
{
    t_graphe_noeud *start, *end, *tempstart, *tempend;
    for(int i = 0; i < racine->size ; i++)
    {
        if(racine->all[i]->has_a_way == FALSE && arrete_len(racine->all[i]->arretes) == 2)
        {
            // ft_printf("Pop! %d\n", i);
            start = racine->all[i]->arretes->link;
            tempstart = racine->all[i];
            tempend = racine->all[i];
            end = racine->all[i]->arretes->next->link;
            while(arrete_len(start->arretes) == 2)
                next_arrete(&start, &tempstart);
            while(arrete_len(end->arretes) == 2)
                next_arrete(&end, &tempend);
            if(arrete_new_large(start, tempstart, end, tempend) != SUCCESS)
                return ERR_MALLOC;
        }
    }
    return SUCCESS;
}