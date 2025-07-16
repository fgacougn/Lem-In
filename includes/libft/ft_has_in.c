/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_has_in.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgacougn <fgacougn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:19:39 by fgacougn          #+#    #+#             */
/*   Updated: 2024/04/04 15:43:46 by fgacougn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_has_in(char *charset, char *str)
{
	int		i;
	char	*tempchar;

	if (!charset || !*charset || !str || !*str)
		return (FAILURE);
	i = 0;
	while (str[i])
	{
		tempchar = charset;
		while (*tempchar)
		{
			if (*tempchar == str[i])
			{
				return (i);
			}
			tempchar++;
		}
		i++;
	}
	return (FAILURE);
}
