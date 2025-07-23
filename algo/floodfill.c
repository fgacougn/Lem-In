#include "algo.h"

void floodfill(t_graphe_racine *terre)
{
    int tofill[terre->size];
    int i = 0;
    int j = 0;
    int k;
    int poids;
    tofill[0] = terre->end->id;
    terre->end->poids = 0;
    while(i <= j)
    {
        k = 0;
        poids = terre->all[tofill[i]]->poids;
        while(terre->all[tofill[i]]->links[k])
        {
            if(terre->all[tofill[i]]->links[k]->poids == -1)
            {
                terre->all[tofill[i]]->links[k]->poids = poids + 1;
                if(terre->all[tofill[i]] != terre->start){
                    j++;
                    tofill[j] = terre->all[tofill[i]]->links[k]->id;
                }
            }
            k++;
        }
        i++;
    }
}