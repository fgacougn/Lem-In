/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitcpy_minus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgacougn <fgacougn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:26:02 by fgacougn          #+#    #+#             */
/*   Updated: 2024/04/04 16:02:31 by fgacougn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**norme(int i, char *strminus, char **split, char **ret)
{
	while (i > 0)
	{
		if (ft_strncmp(strminus, split[i], ft_strlen(strminus)) == 0)
			break ;
		ret[i - 1] = ft_strdup(split[i]);
		if (!ret[i - 1])
		{
			ft_free_split(ret);
			return (0);
		}
		i--;
	}
	i--;
	while (i >= 0)
	{
		ret[i] = ft_strdup(split[i]);
		if (!ret[i])
		{
			ft_free_split(ret);
			return (0);
		}
		i--;
	}
	return (ret);
}

char	**ft_splitcpy_minus(char **split, char *strminus)
{
	int		i;
	char	**ret;

	i = 0;
	ret = split;
	if (ft_is_insplit(split, strminus) == -1)
		return (split);
	while (ret[i] != 0)
		i++;
	ret = malloc((i) * sizeof(char *));
	ft_bzero(ret, i * sizeof(char *));
	if (!ret)
		return (0);
	i--;
	return (norme(i, strminus, split, ret));
}
