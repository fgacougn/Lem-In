/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quote_protection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgacougn <fgacougn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 18:36:18 by fgacougn          #+#    #+#             */
/*   Updated: 2024/04/10 19:00:47 by fgacougn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*themalloc(char *str)
{
	int		len;
	char	*strtemp;

	if (!str)
		return (0);
	len = 0;
	strtemp = str;
	while (*strtemp)
	{
		if (*strtemp == '\'' || *strtemp == '"' || ft_is_in(WHITESPACES,
				*strtemp) != -1)
			len += 2;
		len++;
		strtemp++;
	}
	return (malloc(len + 1));
}

static void	thecopy(char *src, char *dest)
{
	while (*src)
	{
		if (*src == '"' || ft_is_in(WHITESPACES, *src) != -1)
		{
			*(dest++) = '\'';
			*(dest++) = *(src++);
			*(dest++) = '\'';
		}
		else if (*src == '\'')
		{
			*(dest++) = '"';
			*(dest++) = *(src++);
			*(dest++) = '"';
		}
		else
			*(dest++) = *(src++);
	}
	*dest = 0;
}

char	*ft_quote_protection(char *str)
{
	char	*strtemp;

	strtemp = themalloc(str);
	if (!strtemp)
		return (0);
	thecopy(str, strtemp);
	return (strtemp);
}
