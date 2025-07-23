#include "lem-in.h"

int main()
{
    t_graphe_racine * racine= parsing();
    if(!racine)
        return 0;
    floodfill(racine);
    ft_printf("marche %d\n", parcours_floodfill(racine));
    gracine_print(racine);
    gracine_clear(racine);
    return 0;
}