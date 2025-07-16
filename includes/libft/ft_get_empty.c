/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_empty.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgacougn <fgacougn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:03:24 by fgacougn          #+#    #+#             */
/*   Updated: 2023/11/13 18:03:59 by fgacougn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_get_empty(char *retour)
{
	if (!retour)
		return (0);
	free(retour);
	retour = malloc(1);
	if (retour)
		*retour = 0;
	return (retour);
}
