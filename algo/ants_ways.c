#include "algo.h"

int count_ways(t_graphe_racine *terre)
{
    int i =0;
    while(terre->start_ways[i])
        i++;
    return i;
}

void put_fourmi(int ant, char * room)
{
    ft_printf("L%d-%s ", ant, room);
}

void make_ways(int *ways, t_graphe_racine *terre)
{
    
    int i =0;
    while(terre->start_ways[i])
    {
        ways[i] = way_len(terre->start_ways[i]);
        i++;
    }
}

void ants_ways(t_graphe_racine *terre)
{
    // int nb_ants = terre->ants;
    int nb_ants = 12;
    int nb_ways = count_ways(terre);
    if(!nb_ants || !nb_ways)
        return ;
    int ways[nb_ways];
    int ants[nb_ways];
    ft_bzero(ants, sizeof(int) * nb_ways);
    int min;
    make_ways(ways, terre);
    while(nb_ants)
    {
        min = ways[0];
        for(int i = 0; i < nb_ways && nb_ants; i++)
        {
            if(ways[i] == min)
            {
                ways[i]+=1;
                ants[i]+=1;
                nb_ants-=1;
            }
        }
    }
    make_ways(ways, terre);
    int walking[nb_ways][WALKING_SIZE];
    ft_bzero(walking, sizeof(int) * nb_ways * WALKING_SIZE);
    int nb = 0;
    for(int i =0; i< nb_ways ; i++)
    {
        if(ants[i])
        {
            walking[i][WALKING_FIRST] = nb;
            walking[i][WALKING_LNB] = nb;
            walking[i][WALKING_NB] = 0;
            walking[i][WALKING_FIRST_ROOM] = 0;
            walking[i][WALKING_END] = ways[i] - 1;
            nb += ants[i];
            // ants[i]--;
        }
    }
    int ongoing = TRUE;
    while(ongoing)
    {
        ongoing = FALSE;
        for(int i = 0; i < nb_ways ; i++)
        {
            if(walking[i][WALKING_FIRST_ROOM] != walking[i][WALKING_END])
            {
                if(ants[i])
                {
                    ants[i]--;
                    walking[i][WALKING_NB] += 1;
                }
                walking[i][WALKING_LNB] +=1;
                walking[i][WALKING_FIRST_ROOM] +=1;
            }
            
             
            for(int j = 0; j < walking[i][WALKING_NB]; j++)
            {
                // ft_printf("%d nb\n", walking[i][WALKING_LNB]);
                // ft_printf("%d fourmi, %d salle\n", walking[i][WALKING_LNB] - walking[i][WALKING_NB] + j , walking[i][WALKING_FIRST_ROOM] +j );
                put_fourmi(walking[i][WALKING_LNB] - walking[i][WALKING_FIRST_ROOM] + j, terre->start_ways[i]->the_way[walking[i][WALKING_FIRST_ROOM] -j ]->name);
            }
            
            // ft_printf("%d %d\n", walking[i][WALKING_END], walking[i][WALKING_FIRST_ROOM] );
            if(walking[i][WALKING_NB] && walking[i][WALKING_END] == walking[i][WALKING_FIRST_ROOM])
            {
                // ft_printf("sortie!!!");
                walking[i][WALKING_NB] -= 1;
                walking[i][WALKING_FIRST_ROOM] -=1;

            }
            // ft_printf("%d %d\n", i, walking[i][WALKING_NB]);
            if(walking[i][WALKING_NB])
                ongoing = TRUE;
        }
        ft_printf("\n");
    }

}