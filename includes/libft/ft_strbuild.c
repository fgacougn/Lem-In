/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strbuild.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgacougn <fgacougn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 10:56:45 by fgacougn          #+#    #+#             */
/*   Updated: 2024/04/04 15:52:11 by fgacougn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strbuild(char *str1, char *str2, char *str3, char *str4)
{
	int		len[4];
	char	*ret;

	len[0] = ft_strlen(str1);
	len[1] = ft_strlen(str2);
	len[2] = ft_strlen(str3);
	len[3] = ft_strlen(str4);
	ret = ft_calloc(len[0] + len[1] + len[2] + len[3] + 1, 1);
	if (!ret)
		return (0);
	ft_memcpy(ret, str1, len[0]);
	ft_memcpy(ret + len[0], str2, len[1]);
	ft_memcpy(ret + len[0] + len[1], str3, len[2]);
	ft_memcpy(ret + len[0] + len[1] + len[2], str4, len[3]);
	return (ret);
}
