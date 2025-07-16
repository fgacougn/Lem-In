/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgacougn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:39:55 by fgacougn          #+#    #+#             */
/*   Updated: 2023/11/08 17:39:56 by fgacougn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *c);
char	*ft_get_str_zeros(int nb);
char	*ft_get_zeros(int arrondi, char *retour, long long int entier, char c);
char	*ft_add_sign(char *retour, char option);
char	*ft_itoa(int n);
char	*ft_get_space(int arrondi, char *retour, long long int entier, char c);
char	*ft_get_zero_z(int arrondi, char *retour, long long int entier, char c);
char	*ft_get_ecaps(int arrondi, char *retour, long long int entier, char c);

char	*ft_getint(int *options, int entier, int *nb_char)
{
	char	*retour;

	retour = ft_itoa(entier);
	if ((options[2] > -2 && !(entier && options[2] <= 0)))
	{
		retour = ft_get_zeros(options[2], retour, (long long int) entier, '0');
	}
	if (options[6] > -1)
		retour = ft_get_ecaps(options[6], retour, ft_strlen(retour), ' ');
	if (options[1] > 0 && options[2] > -2)
		retour = ft_get_ecaps(options[1], retour, ft_strlen(retour), ' ');
	else if (options[0] > 0)
		retour = ft_get_space(options[0], retour, ft_strlen(retour), ' ');
	else if (options[1] > -1 && options[2] < 1)
	{
		retour = ft_get_zero_z(options[1], retour, (long long int) entier, '0');
	}
	if (options[5] > -1 && entier >= 0)
		retour = ft_add_sign(retour, '+');
	else if (options[4] > -1 && entier >= 0)
		retour = ft_add_sign(retour, ' ');
	nb_char += ft_strlen(retour);
	return (retour);
}
