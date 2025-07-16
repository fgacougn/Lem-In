/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_ijoin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgacougn <fgacougn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:26:58 by fgacougn          #+#    #+#             */
/*   Updated: 2023/12/11 16:29:45 by fgacougn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str_ijoin(char *start, char *intersec, char *end)
{
	char	*temp;
	char	*ret;

	temp = ft_strjoin(start, intersec);
	if (!temp)
		return (0);
	ret = ft_strjoin(temp, end);
	free(temp);
	return (ret);
}
