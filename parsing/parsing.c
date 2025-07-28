#include "parsing.h"

void rien(void *todo){
    todo +=1;
    return;
}

int check_tab(char **tab)
{
    int i;
    int j;

    if (ft_str_startwith(tab[0], "L") == SUCCESS)
    {
        ft_printf("Error: room can't start with L.\n");
        return (1);
    }
    i = 1;
    while (tab[i])
    {
        j = -1;
        while (tab[i][++j])
            if(tab[i][j] != '\n' && !ft_isdigit(tab[i][j]))
            {
                ft_printf("Error: room coord take only int.\n");
                return (1);
            }
        i++;
    }
    return (0);
}

int get_ants(char *line)
{
    int len_line = ft_strlen(line);
    for (int i = 0; i < len_line; i++)
    {
        if(line[i] != '\n' && !ft_isdigit(line[i]))
        {
            ft_printf("Error: invalid numbers of ants.\n");
            return (FAILURE);
        }
    }
    ft_printf("%s", line);
    return(SUCCESS);
}

t_graphe_racine *parsing()
{
    char *line;
    char is_peculiar;
    char breakpoint = 0;
    line = get_next_line(0);
    t_graphe_racine *racine = gracine_new();
    t_list *room = 0;
    if (get_ants(line) == FAILURE)
    {
        free(line);
        racine->size = id_noeud;
        gracine_clear(racine);
        return (NULL);
    }
    racine->ants = ft_llatoi(line);
    free(line);
    line = get_next_line(0);
    while (line && !breakpoint && ft_strlen(line))
    {
        if(line[ft_strlen(line) - 1] == '\n')
            line[ft_strlen(line) - 1] = 0;
        is_peculiar = 0;
        if(ft_str_startwith(line,"##") == SUCCESS)
        {
            ft_putendl_fd(line, 1);
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
            if(line[ft_strlen(line) - 1] == '\n')
                line[ft_strlen(line) - 1] = 0;
        }
        if(ft_str_startwith(line,"#") != SUCCESS || is_peculiar)
        {
            // ft_putendl_fd(line, 1);
            int res = get_room(line, is_peculiar, racine, &room);
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
            ft_putendl_fd(line, 1);
            free(line);
            line = get_next_line(0);
        }
    }
    if(!racine->start || !racine->end)
    {
        free(line);
        racine->size = id_noeud;
        gracine_clear(racine);
        ft_lstclear(&room,(void (*)(void *))gnoeud_del);
        ft_printf("Error: Pas de end ou de start\n");
        return (NULL);
    }
    racine->size = ft_lstsize(room);
    malloc_links(room,racine->size);
    int res;
    while (line && ft_strlen(line))
    {
        if(line[ft_strlen(line) - 1] == '\n')
            line[ft_strlen(line) - 1] = 0;
        if(ft_str_startwith(line,"#") != SUCCESS)
        {
            res = get_links(&room, line);
            if(res != SUCCESS)
            {
                ft_printf("Error: invalid links arguments: %s\n",line);
                free(line);
                racine->size = id_noeud;
                gracine_clear(racine);
                ft_lstclear(&room,(void (*)(void *))gnoeud_del);
                return(NULL);
            }
        }
        
        ft_printf("%s\n",line);
        free(line);
        line = get_next_line(0);
    }
    racine->all = malloc(sizeof(t_graphe_noeud *) *(racine->size +1));
    fill_racine(racine, room);
    ft_lstclear(&room, rien);
    ft_printf("\n");
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
            ft_bzero(((t_graphe_noeud *)list->content)->links,sizeof(t_graphe_noeud *) * (size + 1));
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
    if (!ft_strcmp(*line, "##start"))
    {
        if(rac->start)
        {
            ft_printf("Error: multiple start.\n");
            return (ERR_BAD_ARGS);
        }
        *is_peculiar = PECULIAR_START;
        return SUCCESS;     
    }
    else if(!ft_strcmp(*line ,"##end"))
    {
        if(rac->end)
        {
            ft_printf("Error: multiple end.\n");
            return (ERR_BAD_ARGS);
        }
        *is_peculiar = PECULIAR_END;
        return SUCCESS;
    }
    return (SUCCESS);
}

int get_room(char *line, char is_peculiar, t_graphe_racine *rac, t_list **liste)
{
    char **tab;

    tab = ft_split(line,' ');
    if(ft_splitlen(tab) != 3)
    {
        ft_free_split(tab);
        return(ERR_BAD_ARGS);
    }
    if (check_tab(tab))
    {
        ft_free_split(tab);
        return(ERR_BAD_ARGS);
    }
    if(find_gnoued(*liste, tab[0]))
    {
        ft_printf("Error: multiple room named: %s\n",tab[0]);
        ft_free_split(tab);
        return(ERR_BAD_ARGS);
    }
    t_graphe_noeud *room;
    room = gnoeud_new(tab[0],ft_atoi(tab[1]),ft_atoi(tab[2]));
    if(!room)
    {
        ft_free_split(tab);
        return ERR_MALLOC ;
    }
    room->is_peculiar = is_peculiar;
    if(is_peculiar == PECULIAR_START)
        rac->start = room;
    else if(is_peculiar == PECULIAR_END)
        rac->end = room;
    t_list *lst_room;
    lst_room = ft_lstnew(room);
    ft_lstadd_back(liste, lst_room);
    ft_free_split(tab);
    return(SUCCESS);
}


int get_links(t_list **noeud, char *line)
{
    char **tab;
    t_graphe_noeud *n1;
    t_graphe_noeud *n2;
    int count= 0;

    for (int i = 0; i < (int)ft_strlen(line); i++)
    {
       if (line[i] == '-')
            count++;
    }
    tab = ft_split(line,'-');
    if (ft_splitlen(tab) != 2 || count != 1)
    {
        ft_free_split(tab);
        return(ERR_BAD_ARGS);
    }
    n1 = find_gnoued(*noeud, tab[0]);
    if(tab[1][ft_strlen(tab[1]) - 1] == '\n')
        tab[1][ft_strlen(tab[1]) - 1] = 0;
    n2 = find_gnoued(*noeud, tab[1]);
    int res;
      //res = gnoeud_add_link(n1,n2);
      res = gnoeud_add_arrete(n1,n2);
    if (n1 && n2 && n1 != n2 && res == SUCCESS)
    {
        ft_free_split(tab);
        return (SUCCESS);
    }
    ft_free_split(tab);
    return(FAILURE);
}

