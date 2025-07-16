/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgacougn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:32:30 by fgacougn          #+#    #+#             */
/*   Updated: 2023/11/08 17:32:34 by fgacougn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static unsigned int	getlen(long unsigned int temp)
{
	unsigned int	len;

	len = 1;
	temp /= 10;
	while (temp != 0)
	{
		len++;
		temp /= 10;
	}
	return (len);
}

char	*ft_uitoa(unsigned int n)
{
	long unsigned int	temp;
	unsigned int		len;
	char				*retour;

	temp = n;
	len = getlen(temp);
	if (n > 0)
		temp = n;
	else
		temp = -1 * n;
	retour = (char *)malloc(len + 1);
	if (!retour)
		return (0);
	retour[len--] = '\0';
	retour[len--] = temp % 10 + '0';
	temp /= 10;
	while (temp != 0)
	{
		retour[len--] = temp % 10 + '0';
		temp /= 10;
	}
	return (retour);
}
