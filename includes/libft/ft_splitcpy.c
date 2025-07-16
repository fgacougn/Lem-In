/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitcpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgacougn <fgacougn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:26:02 by fgacougn          #+#    #+#             */
/*   Updated: 2024/04/04 16:02:46 by fgacougn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_splitcpy(char **split)
{
	int		i;
	char	**ret;

	i = 0;
	ret = split;
	while (ret[i] != 0)
		i++;
	ret = malloc((i + 1) * sizeof(char *));
	if (!ret)
		return (0);
	ft_bzero(ret, (i + 1) * sizeof(char **));
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
