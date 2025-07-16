/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_join.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgacougn <fgacougn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 11:18:57 by fgacougn          #+#    #+#             */
/*   Updated: 2024/04/04 14:39:25 by fgacougn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_split_join(char **split)
{
	int		len;
	char	*ret;
	int		i;

	if (!split)
		return (0);
	len = ft_strlen(*split);
	i = 1;
	while (*split && split[i])
		len += 1 + ft_strlen(split[i++]);
	ret = malloc(len + 1);
	if (!ret)
		return (0);
	len = 0;
	ft_memcpy(ret, split[0], ft_strlen(split[0]));
	len = ft_strlen(split[0]);
	i = 1;
	while (split[i])
	{
		ret[len++] = ' ';
		ft_memcpy(&(ret[len]), split[i], ft_strlen(split[i]));
		len += ft_strlen(split[i++]);
	}
	ret[len] = 0;
	return (ret);
}
