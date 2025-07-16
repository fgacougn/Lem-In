/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_sign.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgacougn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:21:59 by fgacougn          #+#    #+#             */
/*   Updated: 2023/11/09 11:22:02 by fgacougn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2);

char	*ft_add_sign(char *retour, char option)
{
	char	*joined;
	char	opt[2];

	opt[0] = option;
	opt[1] = 0;
	joined = ft_strjoin(opt, retour);
	if (retour)
		free(retour);
	retour = joined;
	return (retour);
}
