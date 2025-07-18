#include "graph.h"


int get_room(char *line, char is_peculiar, t_graphe_racine *rac);
int get_links(t_list **noeud, char *line);
int malloc_links(t_list *list, int size);
int get_end_start(char **line, t_graphe_racine *rac, char * is_peculiar);

int check_tab(char **tab)
{
    int i;
    int j;

    ft_printf_split(tab);
    if (ft_str_startwith(tab[0], "L") == SUCCESS)
    {
        ft_printf("Error: invalid room arguments : %s",tab[0]);
        return (1);
    }
    i = 1;
    while (tab[i])
    {
        j = -1;
        while (tab[i][++j])
            if(tab[i][j] != '\n' && !ft_isdigit(tab[i][j]))
            {
                ft_printf("Error: invalid room argumets : %s",tab[i]);
                return (1);
            }
        i++;
    }
    ft_printf("checked succesfully\n");
    return (0);
}

/* Parsing */

t_graphe_racine *parsing()
{
    char *line;
    char is_peculiar;
    char breakpoint = 0;
    line = get_next_line(0);
    t_graphe_racine *racine = gracine_new();
    t_list *room = 0;
    while (line && !breakpoint)
    {
        is_peculiar = 0;
        if(ft_str_startwith(line,"##") == SUCCESS)
        {
            if(get_end_start(&line, racine, &is_peculiar) == ERR_BAD_ARGS)
            {
                free(line);
                racine->size = id_noeud;
                gracine_clear(racine);
                ft_lstclear(&room,(void (*)(void *))gnoeud_del);
                return (NULL);
            }
            free(line);
            line = get_next_line(0);
        }
        ft_printf("\npecu %d, startwith %d\n", ft_str_startwith(line,"#"), is_peculiar);
        if(ft_str_startwith(line,"#") != SUCCESS || is_peculiar)
        {
            int res = get_room(line, is_peculiar, racine);
            ft_printf("res getroom %d\n", res);
            if(res == ERR_BAD_ARGS)
                breakpoint = 1;
            else if(res == ERR_MALLOC)
            {
                free(line);
                racine->size = id_noeud;
                gracine_clear(racine);
                ft_lstclear(&room,(void (*)(void *))gnoeud_del);
                return (NULL);
            }
        }
        if(!breakpoint)
        {
            free(line);
            line = get_next_line(0);
        }
    }
    racine->size = ft_lstsize(room);
    malloc_links(room,racine->size);
    while (line)
    {
        if(get_links(&room, line))
            {
                printf("Error");
                free(line);
                racine->size = id_noeud;
                gracine_clear(racine);
                ft_lstclear(&room,(void (*)(void *))gnoeud_del);
                return(NULL);
            }
        free(line);
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
        {
            if(malloc_links(list->next, size) == ERR_MALLOC)
            {
                free(((t_graphe_noeud *)list->content)->links);
                return ERR_MALLOC;
            }
            return SUCCESS;
        }
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

int get_end_start(char **line, t_graphe_racine *rac, char * is_peculiar)
{
    if (ft_strcmp(*line, "##start"))
    {
        if(rac->start)
            return ERR_BAD_ARGS;
        *is_peculiar = PECULIAR_START;
        // *line = get_next_line(0);
        // t_list  *start = get_room(*line);
        // if(!start)
        //     return(1);
        // ft_lstadd_back(lst,start);
        // t_graphe_noeud * noeud = (t_graphe_noeud *)start->content;
        // rac->start = noeud;
        return SUCCESS;     
    }
    else if(ft_strcmp(*line ,"##end"))
    {
        if(rac->end)
            return ERR_BAD_ARGS;
        *is_peculiar = PECULIAR_END;
        // *line = get_next_line(0);
        // t_list  *end = get_room(*line);
        // if(!end)
        //     return(1);
        // ft_lstadd_back(lst,end);
        // t_graphe_noeud * noeud = (t_graphe_noeud *)end->content;
        // rac->end = noeud;
        return SUCCESS;
    }
    return (ERR_BAD_ARGS);
}

int get_room(char *line, char is_peculiar, t_graphe_racine *rac)
{
    char **tab;

    tab = ft_split(line,' ');
    if (ft_splitlen(tab) != 3)
        return(ERR_BAD_ARGS);
    if(check_tab(tab))
        return (ERR_BAD_ARGS);
    t_graphe_noeud *room;
    room = gnoeud_new(tab[0],ft_atoi(tab[1]),ft_atoi(tab[2]));
    if(!room)
        return ERR_MALLOC;
    room->is_peculiar = is_peculiar;
    if(is_peculiar == PECULIAR_START)
        rac->start = room;
    else if(is_peculiar == PECULIAR_END)
        rac->end = room;
    t_list *lst_room;
    lst_room = ft_lstnew(room);
    return(SUCCESS);
}


int get_links(t_list **noeud, char *line)
{
    char **tab;

    tab = ft_split(line,'-');
    if (ft_splitlen(tab) != 2)
        return(1);
    t_graphe_noeud *n1;
    t_graphe_noeud *n2;
    n1 = find_gnoued(*noeud, tab[0]);
    n2 = find_gnoued(*noeud, tab[0]);
    if (n1 && n2)
    {
        gnoeud_add_link(n1,n2);
        return SUCCESS;
    }
    else
        return(FAILURE);
}




