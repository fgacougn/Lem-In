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

#include "libft.h"
#define PECULIAR_NO 0
#define PECULIAR_END 1
#define PECULIAR_START 2

struct way;

typedef struct graphe_noeud{
    int id;
    char * name;
    struct graphe_noeud ** links;
    char is_peculiar;
    int x;
    int y;
    char seen;
    char has_a_way;
    struct way *first;
} t_graphe_noeud;

t_graphe_noeud * gnoeud_new();
void gnoeud_del();

typedef struct graphe_racine{
    int size;
    t_graphe_noeud *start;
    t_graphe_noeud **all;
    t_graphe_noeud *end;
    struct way **start_ways;
} t_graphe_racine;

t_graphe_racine * gracine_new();
void gracine_add_noeud(t_graphe_noeud*);
void gracine_add_link(char *, char*);
void gracine_del();
void gracine_clear();


typedef struct way{
    int size;
    t_graphe_noeud ** the_way;
} t_way;

t_way * way_new(int size);
void way_del(t_way *);
void ways_del(t_way**, int size );
t_way *way_cpy(t_way *);
void way_add(t_way *start, t_way *end);

#endif
