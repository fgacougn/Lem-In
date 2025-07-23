#include "algo.h"

int way_treatment(t_way **ways_to_add_nodes, char start, int *way_length, int index)
{
    ft_printf("traitement\n");
    int j = 0, cpy = 0, i = index;
    if(!ways_to_add_nodes[i])
        return 0;
    while(ways_to_add_nodes[i]->the_way[j])
        j++;
    struct graphe_noeud *noeud;
    noeud = ways_to_add_nodes[i]->the_way[--j];
    int k = 0;
    // gnoeud_print(noeud->links[k]);
    while(noeud && noeud->links[k])
    {
        // gnoeud_print(noeud->links[k]);
        if(noeud->links[k]->has_a_way)
        {
            ft_printf("conditions %d %d\n", !(noeud->links[k]->seen & start) , (noeud->links[k]->seen != (PECULIAR_END | PECULIAR_START)) );
            if(!(noeud->links[k]->seen & start)  && (noeud->links[k]->seen != (PECULIAR_END | PECULIAR_START)) )
            {
                ft_printf("meeting %s\n",noeud->links[k]->name);
                if(start == PECULIAR_END)
                    way_add(noeud->links[k]->first, ways_to_add_nodes[i]);
                else if(cpy++ == 0)
                    way_add(ways_to_add_nodes[i] , noeud->links[k]->first);
                else 
                {
                    t_way *new;
                    new = way_cpy(ways_to_add_nodes[i]);
                    way_add(new , noeud->links[k]->first);
                    ways_to_add_nodes[*way_length++] = new;
                }
            }
            // noeud->links[k] ->seen =  noeud->links[k] -> seen | noeud->seen | start;
            // noeud->seen = noeud->links[k] -> seen | noeud->seen | start;
        }
        else
        {
            ft_printf("push ! %s to %s\n", noeud->links[k]->name, noeud->name);
            if(cpy++ == 0)
            {
                ways_to_add_nodes[i]->the_way[j + 1] = noeud->links[k];
                noeud->links[k]->first = ways_to_add_nodes[i];
            }
            else 
            {
                t_way *new;
                new = way_cpy(ways_to_add_nodes[i]);
                new->the_way[j + 1] = noeud->links[k];
                ways_to_add_nodes[(*way_length)++] = new;
                noeud->links[k]->first = ways_to_add_nodes[*way_length - 1];
            }
            noeud->links[k] -> seen = start | noeud->links[k] -> seen;
            noeud->links[k]->has_a_way = TRUE;
            noeud->links[k]->first = ways_to_add_nodes[i];

        }
        k++;
    }
    return cpy;
}

// add 1 to ways from x
// | for each way from x
// || for each available node
// |||if this node is already marked
// ||||if it is marked from x
// |||||close this node for this way
// ||||else
// |||||mark is from x
// |||||add this way to the other way that marked the node and add it to the full ways
// |||else
// ||||mark it and add the new node/way
int add_nodes(t_way **ways_to_add_nodes, char start)
{
    int i = 0, nb_ways,result = 0;
    while(ways_to_add_nodes[i])
        i++;
    nb_ways = i;
    while(i + 1)
    {
        result += way_treatment(ways_to_add_nodes, start, &nb_ways, i);
        i--;
    }
    return result;
}
