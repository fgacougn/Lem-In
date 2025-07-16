/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_str_zeros.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgacougn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:35:40 by fgacougn          #+#    #+#             */
/*   Updated: 2023/11/08 17:35:43 by fgacougn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

void	*ft_memset(void *s, int c, size_t n);

char	*ft_get_str_zeros(int nb, char c)
{
	char	*retour;

	if (nb < 1)
		nb = 0;
	retour = malloc(nb + 1);
	if (!retour)
		return (0);
	if (nb)
		ft_memset(retour, c, nb);
	retour[nb] = '\0';
	return (retour);
}
