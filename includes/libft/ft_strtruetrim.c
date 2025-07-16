/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgacougn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:04:46 by fgacougn          #+#    #+#             */
/*   Updated: 2023/11/06 13:04:49 by fgacougn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	is_in(char c, char *set)
{
	unsigned int	selen;

	selen = ft_strlen(set);
	while (selen--)
		if (set[selen] == c)
			return (selen);
	return (-1);
}

char	*ft_strtruetrim(char const *s1, char const *set)
{
	unsigned int	start;
	unsigned int	len;
	unsigned int	lencpy;
	char			*retour;

	start = 0;
	len = ft_strlen((char *)s1);
	lencpy = len;
	while (is_in(s1[start], (char *)set++) != -1)
		start++;
	retour = (char *)malloc(lencpy - start + 1);
	if (retour == 0)
		return (0);
	retour = ft_memcpy(retour, &s1[start], lencpy - start);
	retour[lencpy - start] = '\0';
	return (retour);
}
