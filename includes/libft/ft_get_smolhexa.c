/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_smolhexa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgacougn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:30:16 by fgacougn          #+#    #+#             */
/*   Updated: 2023/11/09 17:30:20 by fgacougn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_get_str_zeros(int nb);
char	*ft_add_dieze(char *retour, char option);
char	*ft_get_zeros(int arrondi, char *retour, long long int entier, char c);
char	*ft_itohexsmol(int n);
char	*ft_get_space(int arrondi, char *retour, long long int entier, char c);
void	*ft_memmove(void *dest, const void *src, size_t n);
char	*ft_get_ecaps(int arrondi, char *retour, long long int entier, char c);

static void	smol_util(int *options, char **retour, unsigned int entier)
{
	if (options[1] > 0 && options[2] > -2)
		*retour = ft_get_ecaps(options[1], *retour, ft_strlen(*retour), ' ');
	else if (options[0] > 0)
		*retour = ft_get_space(options[0], *retour, ft_strlen(*retour), ' ');
	else if (options[1] > 0 && options[2] < 1)
	{
		*retour = ft_get_zeros(options[1], *retour, entier, '0');
	}
}

char	*ft_get_smolhexa(int *options, unsigned int entier, int *nb_char)
{
	char	*retour;

	retour = ft_itohexsmol(entier);
	if ((options[2] > -2 && !(entier && options[2] <= 0)))
	{
		retour = ft_get_zeros(options[2], retour, (long long int) entier, '0');
	}
	if (options[6] > -1)
		retour = ft_get_ecaps(options[6], retour, ft_strlen(retour), ' ');
	smol_util(options, &retour, entier);
	if (options[3] > -1)
		retour = ft_add_dieze(retour, SMOL);
	nb_char += ft_strlen(retour);
	return (retour);
}
