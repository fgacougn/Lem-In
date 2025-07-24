#include "lem-in.h"

int main()
{
    t_graphe_racine * racine= parsing();
    if(!racine)
        return 0;
    // ft_printf("Fin parsing\n");
    floodfill(racine);
    // ft_printf("Fin floodfill\n");
    if(parcours_floodfill(racine) == SUCCESS)
        ants_ways(racine);
    else
        ft_printf("Error no parcours\n");
    // ft_printf("marche %d\n", parcours_floodfill(racine));
    // ft_printf("marche %d\n", parcours_graphe(racine));
    // gracine_print(racine);
    gracine_clear(racine);
    return 0;
    
}