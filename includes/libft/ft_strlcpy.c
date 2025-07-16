/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgacougn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:29:17 by fgacougn          #+#    #+#             */
/*   Updated: 2023/11/06 13:29:19 by fgacougn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned int	len;

	len = ft_strlen((char *)src);
	if (size == 0)
		return (ft_strlen(src));
	if (size <= len)
		len = size - 1;
	size = len;
	dst[len] = '\0';
	while (len --)
		dst[len] = src[len];
	return (ft_strlen(src));
}
