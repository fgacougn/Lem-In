/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_insplit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgacougn <fgacougn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 12:00:45 by fgacougn          #+#    #+#             */
/*   Updated: 2024/02/02 12:00:45 by fgacougn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_insplit(char **charset, char *c)
{
	unsigned int	i;

	i = 0;
	while (charset[i])
		if (!ft_strncmp(c, charset[i++], ft_strlen(c)))
			return (i - 1);
	return (-1);
}
