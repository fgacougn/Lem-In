/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgacougn <fgacougn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:20:20 by fgacougn          #+#    #+#             */
/*   Updated: 2023/11/06 15:20:20 by fgacougn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*retour;

	if (!nmemb || !size)
	{
		nmemb = 1;
		size = 1;
	}
	if ((nmemb * size % nmemb || nmemb * size % size))
		return (0);
	retour = malloc(nmemb * size);
	if (!retour)
		return (0);
	ft_bzero(retour, nmemb * size);
	return (retour);
}
