/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_datoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: fgacougn <fgacougn@student.42.fr>          +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2023/12/15 16:11:25 by fgacougn          #+#    #+#             */
/*   Updated: 2023/12/15 16:11:25 by fgacougn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static double	getretour(const char *nptr, double retour, double deci)
{
	while (*nptr >= '0' && *nptr <= '9')
	{
		retour *= 10;
		retour += *nptr - '0';
		nptr++;
	}
	if (*nptr == '.')
	{
		nptr++;
		while (*nptr >= '0' && *nptr <= '9')
			nptr++;
		nptr--;
		while (*nptr != '.')
		{
			deci /= 10;
			deci += *nptr - '0';
			nptr--;
		}
		deci /= 10;
	}
	retour += deci;
	return (retour);
}

double	ft_datoi(const char *nptr)
{
	double	signe;
	double	retour;
	double	deci;

	retour = 0;
	signe = 1;
	deci = 0;
	if (!nptr || !*nptr)
		return (0);
	while (*nptr == ' ' || (*nptr <= 13 && *nptr >= 9))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			signe = -1;
		nptr++;
	}
	retour = 0;
	return (getretour(nptr, retour, deci) * signe);
}
