/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itohexsmol.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgacougn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:07:32 by fgacougn          #+#    #+#             */
/*   Updated: 2023/11/09 17:07:36 by fgacougn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	getascii(long unsigned int temp, unsigned int len, char *retour)
{
	if (temp % 16 < 10)
		retour[len--] = temp % 16 + '0';
	else
		retour[len--] = temp % 16 + 'a' - 10;
	temp /= 16;
	while (temp != 0)
	{
		if (temp % 16 < 10)
			retour[len--] = temp % 16 + '0';
		else
			retour[len--] = temp % 16 + 'a' - 10;
		temp /= 16;
	}
}

char	*ft_itohexsmol(unsigned int n)
{
	long unsigned int	temp;
	unsigned int		len;
	char				*retour;

	temp = n;
	len = 1;
	temp /= 16;
	while (temp != 0)
	{
		len++;
		temp /= 16;
	}
	temp = n;
	retour = (char *)malloc(len + 1);
	if (!retour)
		return (0);
	retour[len--] = '\0';
	getascii(temp, len, retour);
	return (retour);
}
