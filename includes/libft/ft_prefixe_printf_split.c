/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prefixe_printf_split.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgacougn <fgacougn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:40:12 by fgacougn          #+#    #+#             */
/*   Updated: 2024/04/11 17:59:04 by fgacougn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_prefixe_printf_split(char **split, char *prefixe)
{
	if (!split)
		return ;
	while (*split)
	{
		ft_putstr_fd(prefixe, STDIN_FILENO);
		ft_putendl_fd(*split, STDIN_FILENO);
		split++;
	}
}
