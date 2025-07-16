/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgacougn <fgacougn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:08:09 by fgacougn          #+#    #+#             */
/*   Updated: 2023/11/06 15:08:09 by fgacougn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static void	getlen(int n, long long int *temp, unsigned int *len)
{
	*temp = n;
	*len = 0;
	if (*temp <= 0)
		*len = *len + 1;
	while (*temp != 0)
	{
		*len = *len + 1;
		*temp /= 10;
	}
	*temp = n;
}

// temp = n;
// 	len = 0;
// 	if (temp <= 0)
// 		len ++;
// 	while (temp != 0)
// 	{
// 		len++;
// 		temp /= 10;
// 	}
// 	temp = n;

char	*ft_itoa(int n)
{
	long long int	temp;
	unsigned int	len;
	char			*retour;

	getlen(n, &temp, &len);
	if (n < 0)
		temp *= -1;
	retour = (char *)malloc(len + 1);
	retour[len--] = '\0';
	retour[len--] = temp % 10 + '0';
	temp /= 10;
	while (temp != 0)
	{
		retour[len--] = temp % 10 + '0';
		temp /= 10;
	}
	if (n < 0)
		retour[0] = '-';
	return (retour);
}
