/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ullatoi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgacougn <fgacougn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 12:12:03 by fgacougn          #+#    #+#             */
/*   Updated: 2024/04/09 12:12:03 by fgacougn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned long long int	ft_ullatoi(const char *nptr)
{
	unsigned long long int	retour;

	retour = 0;
	if (!nptr || !*nptr)
		return (0);
	if (*nptr == '-' || *nptr == '+')
		nptr++;
	retour = 0;
	while (*nptr >= '0' && *nptr <= '9')
	{
		retour *= 10;
		retour += *nptr - '0';
		nptr++;
	}
	return (retour);
}
