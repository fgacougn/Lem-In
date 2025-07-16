/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: fgacougn <marvin@42.fr>                    +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2023/11/06 13:12:18 by fgacougn          #+#    #+#             */
/*   Updated: 2023/11/06 13:12:20 by fgacougn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (0);
	if (!s1)
	{
		if (!s2)
			return (0);
		return (*s2);
	}
	if (!s2)
		return (*s1);
	while (*s1 == *s2 && *s1 && i < n - 1)
	{
		s1++;
		s2++;
		i++;
	}
	if (*s1 == *s2)
		return (0);
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
