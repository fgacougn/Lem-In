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
                // terre->all[tofill[i]]->links[k]->links_down[(terre->all[tofill[i]]->links[k]->down)++] = terre->all[tofill[i]];
                // terre->all[tofill[i]]->links_up[(terre->all[tofill[i]]->up)++] = terre->all[tofill[i]]->links[k];
                // terre->all[tofill[i]]->links[k]->from
            }
            // else if(terre->all[tofill[i]]->links[k]->poids <= terre->all[tofill[i]] -> poids)
            // {
            //     // terre->all[tofill[i]]->links[k]->links_down[(terre->all[tofill[i]]->links[k]->down)++] = terre->all[tofill[i]];
            //     // terre->all[tofill[i]]->links_up[(terre->all[tofill[i]]->up)++] = terre->all[tofill[i]]->links[k];
            // }
            k++;
        }
        i++;
    }
}

void floodfill_arretes(t_graphe_racine *terre)
{
    int tofill[terre->size];
    int i = 0;
    int j = 0;
    // int k;
    t_arrete *arrete;
    int poids;
    tofill[0] = terre->end->id;
    terre->end->poids = 0;
    while(i <= j)
    {
        // k = 0;
        arrete = terre->all[tofill[i]]->arretes;
        poids = terre->all[tofill[i]]->poids;
        while(arrete)
        {
            if(arrete->link->poids == -1 || arrete->link->poids > poids + arrete->poids)
            {
                arrete->link->poids = poids + 1;
                if(arrete->link != terre->start){
                    j++;
                    tofill[j] = arrete->link->id;
                }
                // terre->all[tofill[i]]->links[k]->links_down[(terre->all[tofill[i]]->links[k]->down)++] = terre->all[tofill[i]];
                // terre->all[tofill[i]]->links_up[(terre->all[tofill[i]]->up)++] = terre->all[tofill[i]]->links[k];
                // terre->all[tofill[i]]->links[k]->from
            }
            // else if(terre->all[tofill[i]]->links[k]->poids <= terre->all[tofill[i]] -> poids)
            // {
            //     // terre->all[tofill[i]]->links[k]->links_down[(terre->all[tofill[i]]->links[k]->down)++] = terre->all[tofill[i]];
            //     // terre->all[tofill[i]]->links_up[(terre->all[tofill[i]]->up)++] = terre->all[tofill[i]]->links[k];
            // }
            arrete = arrete->next;
        }
        i++;
    }
}