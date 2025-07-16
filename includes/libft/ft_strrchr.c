/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgacougn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:08:43 by fgacougn          #+#    #+#             */
/*   Updated: 2023/11/06 13:08:44 by fgacougn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	*str;

	c %= 256;
	str = (char *)s;
	while (*str)
		str++;
	while (str != s && *str != c)
		str--;
	if (*str != c)
		return (0);
	return (str);
}
