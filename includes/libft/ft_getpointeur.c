/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getpointeur.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgacougn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:24:11 by fgacougn          #+#    #+#             */
/*   Updated: 2023/11/09 11:24:14 by fgacougn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_pitoa(unsigned long long int n);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_get_space(int arrondi, char *retour, long long int entier, char c);
void	*ft_memmove(void *dest, const void *src, size_t n);
char	*ft_get_ecaps(int arrondi, char *retour, long long int entier, char c);

char	*ft_getpointeur(int *options, void *pointeur, int *nb_char)
{
	long long int	valeur;
	char			*retour;
	unsigned int	i;

	if (!pointeur)
		retour = ft_strdup("(nil)");
	else
	{
		valeur = (unsigned long long int) pointeur;
		retour = ft_pitoa(valeur);
		if (retour && options[0] >= 1)
		{
			i = 0;
			while (retour[i + 2] == '0')
				i++;
			ft_memmove(&retour[2], &retour[2 + i], ft_strlen(retour) - 1 - i);
			retour = ft_get_space(options[0], retour, ft_strlen(retour), ' ');
		}
	}
	if (retour && options[6] >= 1)
	{
		retour = ft_get_ecaps(options[6], retour, ft_strlen(retour), ' ');
	}
	nb_char += ft_strlen(retour);
	return (retour);
}
