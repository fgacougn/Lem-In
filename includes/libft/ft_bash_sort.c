/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bash_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgacougn <fgacougn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:26:16 by fgacougn          #+#    #+#             */
/*   Updated: 2024/03/21 11:16:02 by fgacougn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// int	ft_bash_sort(const char *str1, const char *str2)
// {
// 	int index[6];
// 	int ret;

// 	index[0] = ft_has_in(ALPHANUM, (char *)str1);
// 	index[1] = ft_has_in(ALPHANUM, (char *)str2);
// 	// printf ("BASHSORT index %d/%d %s/%s\n", index[0], index[1],str1,str2);
// 	if (index[0] == FAILURE || index[1] == FAILURE)
// 		return (ft_strcmp(str1, str2));
// 	index[2] = ft_is_in(ALPHANUM, str1[index[0]]);
// 	index[3] = ft_is_in(ALPHANUM, str2[index[1]]);
// 	while (index[2] != -1 && index[3] == index[2] && str1[index[0] + 1]
// 		&& str2[index[1] + 1])
// 	{
// 		index[0]++;
// 		index[1]++;
// 		index[2] = ft_is_in(ALPHANUM, str1[index[0]]);
// 		index[3] = ft_is_in(ALPHANUM, str2[index[1]]);
// 	}
// 	index[4] = ft_has_in(ALPHANUM, (char *)&(str1[index[0] + 1]));
// 	index[5] = ft_has_in(ALPHANUM, (char *)&(str2[index[1] + 1]));
// 	if (!str1[index[0] + 1] || index[4] < 0)
// 	{
// 		if (!str2[index[1] + 1] || index[5] < 0)
// 			return (ft_strcmp(str1, str2));
// 		return (str1[index[0] + 1] - str2[index[1] + 1]);
// 	}
// 	if (!str2[index[1] + 1] || index[5] < 0)
// 		return (str1[index[0] + 1] - str2[index[1] + 1]);
// 	// ret = ft_bash_sort(&(str1[index[0]]), &(str2[index[1]]));
// 	if (index[4] >= 0)
// 	{
// 		if (index[5] < 0)
// 			return (1);
// 		else
// 		{
// 			ret = 0;
// 			ft_bash_sort(&(str1[index[0] + 1 + index[4]]), &(str1[index[1]
// 						+ 1 + index[5]]));
// 			if (ret != 0)
// 				return (ret);
// 			return (ft_strcmp(str1, str2));
// 		}
// 	}
// 	else if (index[5] >= 0)
// 		return (-1);
// 	if (index[3] != index[2])
// 		return (index[2] - index[3]);
// 	// printf ("BASHSORT index %d/%d %s/%s\n", index[2], index[3],str1,str2);
// 	ret = ft_strcmp(&(str1[index[0] + 1]), &(str2[index[1] + 1]));
// 	// printf("ret %d\n", ret);
// 	if (ret != 0)
// 		return (ret);
// 	return (ft_strcmp(str1, str2));
// }