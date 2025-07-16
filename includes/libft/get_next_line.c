/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgacougn <fgacougn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:02:31 by fgacougn          #+#    #+#             */
/*   Updated: 2023/11/15 17:16:02 by fgacougn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

t_list	*add_buf(t_list *lst, char *str, int taille);

void	lst_clear(t_list *lst)
{
	if (lst)
	{
		lst_clear(lst->next);
		free(lst);
	}
}

char	*get_str(t_list *str)
{
	char			*retour;
	unsigned int	curseur;
	unsigned int	localcurseur;

	retour = 0;
	if (!str)
		return (0);
	if (str && str->taille > 0)
		retour = (char *)malloc(str->taille + 1);
	if (!retour)
		return (0);
	curseur = 0;
	while (str)
	{
		localcurseur = 0;
		while (str->contenu[localcurseur])
		{
			retour[curseur++] = str->contenu[localcurseur++];
		}
		str = str->next;
	}
	retour[curseur] = 0;
	return (retour);
}

t_list	*get_superstr(t_gnl *gnl, int fd, int *fl, t_list *str)
{
	int	k;

	if (gnl->i == gnl->nb)
	{
		gnl->nb = read(fd, gnl->buf, BUFFER_SIZE);
		gnl->i = 0;
		gnl->buf[gnl->nb] = 0;
	}
	else
		gnl->i++;
	if (!gnl->nb)
		*fl = 1;
	k = gnl->i;
	while (gnl->nb > 0 && gnl->buf[gnl->i] && gnl->buf[gnl->i] != '\n')
		gnl->i++;
	if (gnl->buf[gnl->i] == '\n' || gnl->buf[gnl->i] == 10)
		*fl = 1;
	if (!str && gnl->nb > 0)
		str = add_buf(str, &gnl->buf[k], gnl->i - k + *fl);
	else if (gnl->nb > 0 && add_buf(str, &gnl->buf[k], gnl->i - k + *fl) == 0)
		lst_clear(str);
	return (str);
}

char	*get_next_line(int fd)
{
	static t_gnl	gnl;
	t_list			*str;
	int				fl;
	char			*retour;

	fl = 0;
	if (gnl.start == 0)
	{
		gnl.i = 0;
		gnl.nb = 0;
		gnl.start++;
	}
	str = 0;
	while (!fl && gnl.nb > -1)
	{
		str = get_superstr(&gnl, fd, &fl, str);
		if (!str)
			break ;
	}
	retour = get_str(str);
	lst_clear(str);
	return (retour);
}
