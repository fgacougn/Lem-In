/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgacougn <fgacougn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:47:59 by fgacougn          #+#    #+#             */
/*   Updated: 2024/04/04 14:40:30 by fgacougn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	partition(char **split, int start, int end, int (*cmp)(const char *,
			const char *))
{
	int		pivot_index;
	char	*pivot;
	char	*temp;
	int		i;

	pivot_index = start;
	pivot = split[end];
	i = start;
	while (i < end)
	{
		if (cmp(split[i], pivot) < 0)
		{
			temp = split[i];
			split[i] = split[pivot_index];
			split[pivot_index] = temp;
			pivot_index++;
		}
		i++;
	}
	temp = split[pivot_index];
	split[pivot_index] = pivot;
	split[end] = temp;
	return (pivot_index);
}

static void	quick_sort(char **split, int start, int end,
		int (*cmp)(const char *, const char *))
{
	int	pivot;

	if (start < end)
	{
		pivot = partition(split, start, end, cmp);
		quick_sort(split, start, pivot - 1, cmp);
		quick_sort(split, pivot + 1, end, cmp);
	}
}

void	ft_split_sort(char **split, int (*cmp)(const char *, const char *))
{
	quick_sort(split, 0, ft_splitlen(split) - 1, cmp);
}
