#include "lem-in.h"

int main()
{
    t_graphe_racine * racine = parsing();
    if(!racine)
        return 0;
    // ft_printf("Fin parsing\n");
    graph_simplify(racine);
    floodfill_arretes(racine);
    // ft_printf("Fin floodfill\n");
    parcours_floodfill_arrete(racine);
    set_tab_way(racine->start_ways);
    gracine_clean_way(racine);
    // gracine_print(racine);
    parcours_edmonds_karps(racine);
    // gracine_print(racine);
    // if(parcours_floodfill_arrete(racine) == SUCCESS)
    //     ants_ways(racine);
    // else
    //     ft_printf("Error no parcours\n");
    // ft_printf("marche %d\n", parcours_floodfill(racine));
    // ft_printf("marche %d\n", parcours_graphe(racine));
    // gracine_print(racine);

    int i = 0;
    // ft_printf("startways\n");
    // if(racine->start_ways)
    // while (racine->start_ways[i])
    // {
    //     way_print(racine->start_ways[i]);
    //     ft_printf("\n");
    //     i++;
    // }
    i = 0;
    // ft_printf("ek\n");
    // if(racine->ek_ways)
    // while (racine->ek_ways[i])
    // {
    //     way_print(racine->ek_ways[i]);
    //     ft_printf("\n");
    //     i++;
    // }
    // i = 0;
    draw_ways(racine);
    // ft_printf("drawn\n");
    // if(racine->drawn_ways)
    // while (racine->drawn_ways[i])
    // {
    //     way_print(racine->drawn_ways[i]);
    //     ft_printf("\n");
    //     i++;
    // }
    // ft_printf("%d ways\n", i);
    while (racine->start_ways[i])
    {
        way_print(racine->start_ways[i]);
        ft_printf("\n");
        i++;
    }
    gracine_clear(racine);
    return 0;
}