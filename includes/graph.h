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
#define WAY_TRUE 1
#define WAY_FALSE 0
#define WAY_REVERSABLE -1

struct way;
extern int id_noeud;
struct graphe_noeud;

typedef struct arrete{
    struct arrete *next;
    struct arrete *before;
    struct arrete *linkedto;
    int poids;
    struct graphe_noeud **inside;
    char is_direct;
    char has_a_way;
    char seen;
    struct graphe_noeud *link;
} t_arrete;

typedef struct graphe_noeud{
    int id;
    char * name;
    int up;
    int down;
    int from;
    t_arrete *arretes;
    struct graphe_noeud ** links;
    struct graphe_noeud ** links_up;
    struct graphe_noeud ** links_down;
    char is_peculiar;
    int x;
    int y;
    char seen;
    char has_a_way;
    struct way *first;
    int poids;
} t_graphe_noeud;

t_arrete *arrete_new(t_graphe_noeud *to);
int arrete_new_large(t_graphe_noeud *from, t_graphe_noeud *from2, t_graphe_noeud *to, t_graphe_noeud *to2);
void arrete_del(t_arrete *);
void arrete_clear(t_arrete *);
int arrete_len(t_arrete *);
int arrete_add_front(t_arrete **front, t_arrete *);
int arrete_pop(t_arrete **front, t_arrete *);
void print_arretes(t_arrete *);
t_arrete *arrete_cpy(t_arrete *tocpy);
void next_arrete(t_graphe_noeud **from, t_graphe_noeud **before);


t_graphe_noeud * gnoeud_new(char *name, int x, int y);
int gnoeud_add_link(t_graphe_noeud *first, t_graphe_noeud *second);
int gnoeud_has_arrete(t_graphe_noeud *first, t_graphe_noeud *second);
int gnoeud_add_arrete(t_graphe_noeud *first, t_graphe_noeud *second);
void gnoeud_del(t_graphe_noeud *del);
t_graphe_noeud *find_gnoued(t_list *lst, char *name);
void gnoeud_print(t_graphe_noeud *);


typedef struct graphe_racine{
    int size;
    int ants;
    t_graphe_noeud *start;
    t_graphe_noeud **all;
    t_graphe_noeud *end;
    struct way **start_ways;
    struct way **drawn_ways;
} t_graphe_racine;

t_graphe_racine * gracine_new(void);
void gracine_add_noeud(t_graphe_racine *dest, t_graphe_noeud *add);
void gracine_del(t_graphe_racine *target);
void gracine_clear(t_graphe_racine *target);
void gracine_print(t_graphe_racine *);
void gracine_clean_seen(t_graphe_racine *);
void gracine_clean_way(t_graphe_racine *);
t_graphe_racine *parsing();
int set_link_tabs(t_graphe_racine *);
int draw_ways(t_graphe_racine *);


typedef struct way{
    int size;
    t_graphe_noeud ** the_way;
    t_arrete *arretes;
    t_arrete *last;
} t_way;

t_way * way_new(int size);
void way_del(t_way *);
void ways_del(t_way**, int size );
t_way *way_cpy(t_way *);
void way_add(t_way *start, t_way *end);
void way_print(t_way *);
int way_len(t_way *);
void path_clear(t_way *);
void set_way(t_way *);
void sort_ways(t_way **);
int way_addback(t_way *, t_arrete *);
t_arrete *way_popback(t_way *);
int way_clearback(t_way *);
int set_tab_way(t_way **);

#endif
