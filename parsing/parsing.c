#include "graph.h"

/* Utils */
int tab_size(char **tab)
{
    int res;
    int i;

    i = 0;
    while(tab[i])
    {
        i++;
        res++;
    }
    return(res);
}

int check_tab(char **tab)
{
    int i;
    int j;

    if (ft_str_startwith(tab[0], "L"))
    {
        ft_printf("Error: invalid room argumets : %s",tab[0]);
        return (1);
    }
    i = 1;
    while (tab[i])
    {
        j = -1;
        while (tab[i][++j])
            if(ft_isdigit(tab[i][j]))
            {
                ft_printf("Error: invalid room argumets : %s",tab[i]);
                return (1);
            }
        i++;
    }
    return (0);
}

/* Parsing */

t_graphe_racine *parsing()
{
    char *line;
    line = get_next_line(0);
    t_graphe_racine *racine = gracine_new();
    t_list **room;
    while (line)
    {
        if(ft_str_startwith(line,"##"))
            if(get_end_start(*line, racine, room))
                return (NULL);
        if(ft_str_startwith(line,"#"))
            line = get_next_line(0);
        if(get_room(line))
            break;
        line = get_next_line(0);
    }
    racine->size = ft_lstsize(room);
    malloc_links(room,racine->size);
    while (line)
    {
        if(get_links(room, line))
            {
                printf("Error");
                ft_lstclear(room,gnoeud_del);
                return(NULL);
            }
        line = get_next_line(0);
    }
    racine->all = malloc(sizeof(t_graphe_noeud *) *(racine->size +1));
    return (racine);
}

int malloc_links(t_list *list, int size)
{
    if(list)
    {
        ((t_graphe_noeud *)list->content)->links = malloc(sizeof(t_graphe_noeud *) * (size + 1));
        if (((t_graphe_noeud *)list->content)->links)
            if(malloc_links(list->next, size) == ERR_MALLOC)
            {
                free(((t_graphe_noeud *)list->content)->links);
                return ERR_MALLOC;
            }
            return SUCCESS;
        return ERR_MALLOC;
    }
    return SUCCESS;
}

void fill_racine(t_graphe_racine *racine, t_list * liste)
{
    if(liste)
    {
        fill_racine(racine, liste->next);
        racine->all[((t_graphe_noeud *) liste->content)->id] = (t_graphe_noeud *) liste->content;
    }
}

int *get_end_start(char **line, t_graphe_racine *rac, t_list **lst)
{
    if (ft_strcmp(*line, "##start"))
    {
        *line = get_next_line(0);
        t_list  *start = get_room(*line);
        if(!start)
            return(1);
        ft_lstadd_back(lst,start);
        t_graphe_noeud * noeud = (t_graphe_noeud *)start->content;
        rac->start = noeud;        
    }
    else if(ft_strcmp(*line ,"##end"))
    {
        *line = get_next_line(0);
        t_list  *end = get_room(*line);
        if(!end)
            return(1);
        ft_lstadd_back(lst,end);
        t_graphe_noeud * noeud = (t_graphe_noeud *)end->content;
        rac->end = noeud;
    }
    return (0);
}

t_list *get_room(char *line)
{
    char **tab;

    tab = ft_split(line,' ');
    if (tab_size != 3)
        return(NULL);
    if(!check_tab(tab))
        return (NULL);
    t_graphe_noeud *room;
    room = gnoeud_new(tab[0],tab[1],tab[2]);
    t_list *lst_room;
    lst_room = ft_lstnew(room);
    return(lst_room);
}


int get_links(t_list **noeud, char *line)
{
    char **tab;

    tab = ft_split(line,'-');
    if (tab_size != 2)
        return(1);
    t_graphe_noeud *n1;
    t_graphe_noeud *n2;
    n1 = find_gnoued(noeud, tab[0]);
    n2 = find_gnoued(noeud, tab[0]);
    if (n1 && n2)
        gnoeud_add_link(tab[0],tab[1]);
    else
        return(0);
}




