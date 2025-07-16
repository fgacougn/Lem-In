/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: fgacougn <fgacougn@student.42.fr>          +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2023/11/06 15:30:49 by fgacougn          #+#    #+#             */
/*   Updated: 2023/11/06 15:30:49 by fgacougn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long long int	ft_llatoi(const char *nptr)
{
	int				signe;
	long long int	retour;

	retour = 0;
	signe = 1;
	if (!nptr || !*nptr)
		return (0);
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			signe = -1;
		nptr++;
	}
	retour = 0;
	while (*nptr >= '0' && *nptr <= '9')
	{
		retour *= 10;
		retour += *nptr - '0';
		nptr++;
	}
	return (retour * signe);
}
