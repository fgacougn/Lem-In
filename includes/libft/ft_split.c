/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgacougn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:37:45 by fgacougn          #+#    #+#             */
/*   Updated: 2023/11/06 13:37:47 by fgacougn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static unsigned int	cpt_words(char *s, char c)
{
	unsigned int	i;

	i = 0;
	if (*s && *(s++) != c)
		i++;
	while (*s)
	{
		if (*s != c && *(s - 1) == c)
			i++;
		s++;
	}
	return (i);
}

void	ft_free_split(char **split)
{
	unsigned int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

static int	util_split(char **rer, unsigned int cpt, char *tp, unsigned int ln)
{
	rer[cpt] = ft_strdup(&tp[ln]);
	if (rer[cpt] == 0)
	{
		free(tp);
		ft_free_split(rer);
		return (0);
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	unsigned int	cpt;
	char			**retour;
	char			*temp;
	unsigned int	len;

	cpt = cpt_words((char *)s, c);
	retour = (char **)ft_calloc((cpt + 1) * sizeof(char *), 1);
	if (retour == 0)
		return (retour);
	retour[cpt--] = 0;
	temp = ft_strdup(s);
	if (!temp)
	{
		free(retour);
		return (0);
	}
	len = ft_strlen(temp);
	while (len--)
		if (temp[len] == c)
			temp[len] = '\0';
	else if (len == 0 || temp[len - 1] == c)
		if (util_split(retour, cpt--, temp, len) == 0)
			return (0);
	free(temp);
	return (retour);
}
