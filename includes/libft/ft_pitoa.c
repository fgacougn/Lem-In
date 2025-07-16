/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgacougn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:51:24 by fgacougn          #+#    #+#             */
/*   Updated: 2023/11/08 17:51:27 by fgacougn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static void	pitoa_util(long long unsigned int t, char *r, size_t l)
{
	if (t % 16 < 10)
		r[2 + l--] = t % 16 + '0';
	else
		r[2 + l--] = t % 16 + 'a' - 10;
	t /= 16;
	while (t != 0)
	{
		if (t % 16 < 10)
			r[2 + l--] = t % 16 + '0';
		else
			r[2 + l--] = t % 16 + 'a' - 10;
		t /= 16;
	}
}

char	*ft_pitoa(unsigned long long int n)
{
	unsigned long long int	temp;
	size_t					len;
	char					*retour;

	temp = n;
	len = 0;
	while (temp != 0)
	{
		len ++;
		temp /= 16;
	}
	temp = n;
	retour = (char *)malloc(len + 3);
	if (!retour)
		return (0);
	retour[2 + len--] = '\0';
	pitoa_util(temp, retour, len);
	retour[0] = '0';
	retour[1] = 'x';
	return (retour);
}
