/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgacougn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:20:15 by fgacougn          #+#    #+#             */
/*   Updated: 2023/11/06 13:20:16 by fgacougn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	len;
	char			*retour;

	if (!f)
		return (0);
	len = ft_strlen((char *)s);
	retour = (char *)malloc(len + 1);
	if (retour == 0)
		return (0);
	retour[len] = '\0';
	while (len--)
		retour[len] = f(len, s[len]);
	return (retour);
}
