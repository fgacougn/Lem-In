/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgacougn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:01:28 by fgacougn          #+#    #+#             */
/*   Updated: 2023/11/06 13:01:31 by fgacougn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	slen;
	char			*retour;

	slen = ft_strlen(s);
	if (start > slen)
		len = 0;
	else if (len + start > slen)
		len = slen - start;
	retour = (char *) malloc (len + 1);
	if (!retour)
		return (0);
	if (len > 0)
		ft_memcpy(retour, &s[start], len);
	retour[len] = '\0';
	return (retour);
}
