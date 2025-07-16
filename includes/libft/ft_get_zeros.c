/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_zeros.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgacougn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:35:58 by fgacougn          #+#    #+#             */
/*   Updated: 2023/11/08 17:36:01 by fgacougn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

char	*ft_get_str_zeros(int nb, char c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_get_empty(char *retour);

static int	get_zeros_util(char **joined, char **strzeros, char *retour)
{
	*joined = ft_strjoin("-", *strzeros);
	free(*strzeros);
	if (!*joined)
		return (0);
	*strzeros = *joined;
	*joined = ft_strjoin(*strzeros, retour + 1);
	return (1);
}

static void	end_get(char **retour, char *joined, char **strzeros)
{
	if (*retour)
		free(*retour);
	*retour = joined;
	if (*strzeros)
		free(*strzeros);
}

char	*ft_get_zeros(int arrondi, char *retour, long long int entier, char c)
{
	char	*joined;
	char	*strzeros;

	if (arrondi <= 0 && retour && *retour)
		retour = ft_get_empty(retour);
	if (entier < 0 && (arrondi - ft_strlen(retour) + 1) > 0)
	{
		strzeros = ft_get_str_zeros(arrondi - ft_strlen(retour) + 1, c);
		if (strzeros)
		{
			if (!get_zeros_util(&joined, &strzeros, retour))
				return (0);
		}
		else
			return (0);
	}
	else
	{
		strzeros = ft_get_str_zeros(arrondi - ft_strlen(retour), c);
		joined = ft_strjoin(strzeros, retour);
	}
	end_get(&retour, joined, &strzeros);
	return (retour);
}
