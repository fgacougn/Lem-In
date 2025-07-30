#include "lem-in.h"

int main()
{
    t_graphe_racine * racine= parsing();
    if(!racine)
        return 0;
    // ft_printf("Fin parsing\n");
    graph_simplify(racine);
    floodfill_arretes(racine);
    // ft_printf("Fin floodfill\n");
    parcours_floodfill_arrete(racine);
    gracine_clean_way(racine);
    // parcours_edmonds_karps(racine);

    // if(parcours_floodfill_arrete(racine) == SUCCESS)
    //     ants_ways(racine);
    // else
    //     ft_printf("Error no parcours\n");
    // ft_printf("marche %d\n", parcours_floodfill(racine));
    // ft_printf("marche %d\n", parcours_graphe(racine));
    // gracine_print(racine);

    // int i = 0;
    // while (racine->start_ways[i])
    // {
    //     way_print(racine->start_ways[i]);
    //     ft_printf("\n");
    //     i++;
    // }
    set_tab_way(racine->start_ways);
    
    gracine_clear(racine);
    return 0;
}