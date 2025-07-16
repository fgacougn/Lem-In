/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgacougn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:10:21 by fgacougn          #+#    #+#             */
/*   Updated: 2023/11/06 13:10:24 by fgacougn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlen(const char *s);

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned long int	i;
	char				*bigt;
	unsigned int		llen;

	llen = len;
	bigt = (char *)big;
	if (!*little)
		return ((char *)big);
	if (len == 0 || ft_strlen(little) > len)
		return (0);
	while (*bigt && llen)
	{
		if (*little == *bigt)
		{
			i = 1;
			while (*(little + i) == *(bigt + i)
				&& *(little + i) && i < llen)
				i++;
			if (!*(little + i))
				return ((char *)bigt);
		}
		bigt++;
		llen--;
	}
	return (0);
}
