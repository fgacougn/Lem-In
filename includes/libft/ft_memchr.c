/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgacougn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:53:09 by fgacougn          #+#    #+#             */
/*   Updated: 2023/11/06 13:53:11 by fgacougn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;

	c = (unsigned char)c;
	str = (unsigned char *) s;
	while (n-- && *str != c)
		str++;
	if (!++n)
		return (0);
	return ((void *)str);
}
