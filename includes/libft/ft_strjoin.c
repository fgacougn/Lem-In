/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: fgacougn <marvin@42.fr>                    +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2023/11/06 13:32:51 by fgacougn          #+#    #+#             */
/*   Updated: 2023/11/06 13:32:53 by fgacougn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dest, const void *src, size_t n);

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	s1len;
	unsigned int	s2len;
	char			*retour;

	s1len = ft_strlen((char *)s1);
	s2len = ft_strlen((char *)s2);
	retour = (char *)malloc(s1len + s2len + 1);
	if (!retour)
		return (0);
	retour = ft_memcpy(retour, s1, s1len);
	ft_memcpy(retour + s1len, s2, s2len + 1);
	return (retour);
}
