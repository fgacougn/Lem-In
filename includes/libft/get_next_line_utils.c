/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgacougn <fgacougn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:53:49 by fgacougn          #+#    #+#             */
/*   Updated: 2023/11/15 12:14:13 by fgacougn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <stdio.h>

t_list	*new_lst(void)
{
	t_list	*lst;

	lst = (t_list *)malloc(sizeof(t_list));
	if (!lst)
		return (0);
	lst->next = 0;
	lst->nombre = 0;
	lst->taille = 0;
	lst->contenu[0] = 0;
	return (lst);
}

t_list	*add_buffer_init(t_list **lst)
{
	t_list	*init;

	if (!*lst)
	{
		*lst = new_lst();
		if (!*lst)
			return (0);
	}
	init = *lst;
	while (*lst && (*lst)->next)
		*lst = (*lst)->next;
	if ((*lst)->nombre == MAX_S_LIST)
	{
		(*lst)->next = new_lst();
		if (!*lst)
			return (0);
		*lst = (*lst)->next;
	}
	return (init);
}

t_list	*add_buf(t_list *lst, char *str, int taille)
{
	int		cpt;
	t_list	*init;

	init = add_buffer_init(&lst);
	if (!init)
		return (0);
	cpt = 0;
	while (cpt < taille && lst->nombre + cpt < MAX_S_LIST)
	{
		lst->contenu[lst->nombre + cpt] = str[cpt];
		cpt++;
	}
	lst->nombre += cpt;
	lst->contenu[lst->nombre] = 0;
	if (cpt != taille)
		init = add_buf(init, &str[cpt], taille - cpt);
	init->taille += cpt;
	return (init);
}
