/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_split.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgacougn <fgacougn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:40:12 by fgacougn          #+#    #+#             */
/*   Updated: 2024/04/11 17:59:14 by fgacougn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printf_split(char **split)
{
	if (!split)
		return ;
	while (*split)
	{
		ft_putendl_fd(*split, STDIN_FILENO);
		split++;
	}
}
