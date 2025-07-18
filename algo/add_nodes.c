#include "algo.h"

int way_treatment(t_way **ways_to_add_nodes, char start, int *way_length, int index)
{

    int j = 0, cpy = 0;
    while(ways_to_add_nodes[i]->the_way[j])
        j++;
    graphe_noeud *noeud;
    noeud = ways_to_add_nodes[i]->the_way[j];
    int k = 0;
    while(noeud->links[k])
    {
        if(noeud->links[k]->has_a_way)
        {
            if(noeud->links[k]->seen & start && ! (noeud->links[k]->seen & 3))
            {
                if(start == PECULIAR_END)
                    way_add(noeud->links[k]->first, ways_to_add_nodes[i]->the_way[j]);
                else if(cpy++ = 0)
                    way_add(ways_to_add_nodes[i]->the_way[j] , noeud->links[k]->first);
                else 
                {
                    t_way *new;
                    new = way_cpy(ways_to_add_nodes[i]);
                    way_add(new , noeud->links[k]->first);
                    ways_to_add_nodes[*way_length++] = new;
                }
            }
            noeud->links[k] -> seen += start;
        }
        else
        {
            if(cpy++ = 0)
                ways_to_add_nodes[i]->the_way[j + 1] = noeud->links[k];
            else 
            {
                t_way *new;
                new = way_cpy(ways_to_add_nodes[i]);
                new->the_way[k + 1] = noeud->links[k];
                ways_to_add_nodes[*way_length++] = new;
            }
            noeud->links[k] -> seen += start;
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
