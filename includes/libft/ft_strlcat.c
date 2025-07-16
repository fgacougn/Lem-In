/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgacougn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:30:51 by fgacougn          #+#    #+#             */
/*   Updated: 2023/11/06 13:30:52 by fgacougn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	dstlen;
	unsigned int	srcpy;

	dstlen = 0;
	while (dst[dstlen] || size == 0)
		if (size == dstlen++)
			return (ft_strlen(src) + size);
	srcpy = 0;
	while (src[srcpy] && dstlen + srcpy < size - 1)
	{
		dst[dstlen + srcpy] = src[srcpy];
		srcpy++;
	}
	dst[dstlen + srcpy] = '\0';
	return (dstlen + ft_strlen(src));
}
