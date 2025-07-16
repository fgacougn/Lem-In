/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgacougn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:47:50 by fgacougn          #+#    #+#             */
/*   Updated: 2023/11/06 13:47:51 by fgacougn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char			*str;
	char			*str2;
	unsigned int	i;

	if (dest == src)
		return (dest);
	str = (char *)dest;
	str2 = (char *)src;
	if (dest > src)
		while (n--)
			*(str + n) = *(str2 + n);
	if (dest < src)
	{
		i = 0;
		while (i < n)
		{
			str[i] = str2[i];
			i++;
		}
	}
	return (dest);
}
