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

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define MAX_S_LIST 10000
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_list
{
	char			contenu[MAX_S_LIST + 1];
	unsigned int	nombre;
	unsigned int	taille;
	struct s_list	*next;
}	t_list;

typedef struct s_gnl
{
	char	buf[BUFFER_SIZE + 1];
	int		i;
	int		nb;
	int		start;
	t_list	*str;
}	t_gnl;

char	*get_next_line(int fd);

#endif
