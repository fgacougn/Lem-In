/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itohexbigold.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgacougn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:09:35 by fgacougn          #+#    #+#             */
/*   Updated: 2023/11/09 11:09:38 by fgacougn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static void	util(char *retour, unsigned int len, long unsigned int temp)
{
	retour[len--] = '\0';
	if (temp % 16 < 10)
		retour[len--] = temp % 16 + '0';
	else
		retour[len--] = temp % 16 + 'A' - 10;
	temp /= 16;
	while (temp != 0)
	{
		if (temp % 16 < 10)
			retour[len--] = temp % 16 + '0';
		else
			retour[len--] = temp % 16 + 'A' - 10;
		temp /= 16;
	}
}

char	*ft_itohexbigold(unsigned int n)
{
	long unsigned int	temp;
	unsigned int		len;
	char				*retour;

	temp = n;
	len = 1;
	temp /= 16;
	while (temp != 0)
	{
		len ++;
		temp /= 16;
	}
	temp = n;
	retour = (char *)malloc(len + 1);
	if (retour)
		util(retour, len, temp);
	return (retour);
}
