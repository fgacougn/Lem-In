/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: fgacougn <marvin@42.fr>                    +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2023/11/06 13:12:18 by fgacougn          #+#    #+#             */
/*   Updated: 2023/11/06 13:12:20 by fgacougn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *s);

int	ft_strcmp(const char *s1, const char *s2)
{
	return (ft_strncmp(s1, s2, ft_strlen(s1) + 1));
}
