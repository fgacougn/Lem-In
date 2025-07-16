/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_envp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgacougn <fgacougn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 12:52:19 by fgacougn          #+#    #+#             */
/*   Updated: 2023/12/08 18:34:11 by fgacougn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_get_envp(char **envp)
{
	int		check[ENVP_SIZE];
	int		i;
	char	**ret;

	ret = malloc(ENVP_SIZE * sizeof(char *));
	if (!ret)
		return (0);
	ft_bzero(check, ENVP_SIZE * sizeof(int));
	ft_bzero(ret, ENVP_SIZE * sizeof(char *));
	i = 0;
	while (envp[i])
	{
		if (ft_str_startwith(envp[i], "PATH=") == SUCCESS)
		{
			ret[ENVP_PATH] = &envp[i][ft_strlen("PATH=")];
			check[ENVP_PATH] = 1;
		}
		if (ft_str_startwith(envp[i], "PWD=") == SUCCESS)
		{
			ret[ENVP_PWD] = &envp[i][ft_strlen("PWD=")];
			check[ENVP_PWD] = 1;
		}
		i++;
	}
	return (ret);
}
