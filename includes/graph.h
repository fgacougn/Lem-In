/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgacougn <fgacougn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:02:13 by fgacougn          #+#    #+#             */
/*   Updated: 2023/11/15 16:34:57 by fgacougn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPH_H
# define GRAPH_H

#include "./libft/libft.h"
#define PECULIAR_NO 0
#define PECULIAR_END 1
#define PECULIAR_START 2

extern int id_noeud;

typedef struct graphe_noeud{
    int id;
    char * name;
    struct graphe_noeud ** links;
    char is_peculiar;
    int x;
    int y;
    char seen;
    char has_a_way;
} t_graphe_noeud;

t_graphe_noeud * gnoeud_new(char *name, int x, int y);
void gnoeud_add_link(t_graphe_noeud *first, t_graphe_noeud *second);
void gnoeud_del(t_graphe_noeud *del);
t_graphe_noeud *find_gnoued(t_list *lst, char *name);


typedef struct graphe_racine{
    int size;
    t_graphe_noeud *start;
    t_graphe_noeud **all;
    t_graphe_noeud *end;
} t_graphe_racine;

t_graphe_racine * gracine_new(void);
void gracine_add_noeud(t_graphe_racine *dest, t_graphe_noeud *add);
void gracine_del(t_graphe_racine *target);
void gracine_clear(t_graphe_racine *target);
t_graphe_racine *parsing();


typedef struct way{
    t_graphe_noeud ** the_way;
} t_way;

t_way * way_new();
void way_del();

#endif
