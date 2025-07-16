/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgacougn <fgacougn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:26:46 by fgacougn          #+#    #+#             */
/*   Updated: 2023/11/06 15:26:46 by fgacougn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tete;
	void	*val;

	if (!lst || !f || !del)
		return (0);
	val = f(lst->content);
	tete = ft_lstnew(val);
	if (!tete)
	{
		del(val);
		return (0);
	}
	if (lst->next)
	{
		tete->next = ft_lstmap(lst->next, f, del);
		if (!tete->next)
			ft_lstclear(&tete, del);
	}
	return (tete);
}
