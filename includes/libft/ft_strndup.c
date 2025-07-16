/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: fgacougn <marvin@42.fr>                    +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2023/11/06 13:35:44 by fgacougn          #+#    #+#             */
/*   Updated: 2023/11/06 13:35:46 by fgacougn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		ft_imin(int a, int b);
size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dest, const void *src, size_t n);

char	*ft_strndup(const char *s, int le)
{
	unsigned int	len;
	char			*retour;

	if (!s)
		return (0);
	len = ft_imin(ft_strlen((char *)s), le);
	retour = (char *)malloc(len + 1);
	if (retour == 0)
		return (0);
	retour = ft_memcpy(retour, s, len);
	retour[len] = 0;
	return (retour);
}
