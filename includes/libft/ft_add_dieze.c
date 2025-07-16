/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_dieze.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgacougn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:06:42 by fgacougn          #+#    #+#             */
/*   Updated: 2023/11/09 11:06:48 by fgacougn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2);

char	*ft_add_dieze(char *retour, char option)
{
	char	*joined;

	if (retour[0] == '0')
		return (retour);
	if (option == SMOL)
		joined = ft_strjoin("0x", retour);
	if (option == BIGOLD)
		joined = ft_strjoin("0X", retour);
	if (retour)
		free(retour);
	retour = joined;
	return (retour);
}
