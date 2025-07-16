/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: fgacougn <marvin@42.fr>                    +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2023/11/06 13:37:45 by fgacougn          #+#    #+#             */
/*   Updated: 2023/11/06 13:37:47 by fgacougn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	thewhile(char **s, char *c, unsigned int *i)
{
	while (**s != 0)
	{
		if (**s != *c && *(*s - 1) == *c)
			(*i)++;
		if (**s == '"')
		{
			(*s)++;
			while (**s && **s != '"')
				(*s)++;
		}
		if (**s == '\'')
		{
			(*s)++;
			while (**s && **s != '\'')
				(*s)++;
		}
		(*s)++;
	}
}

static unsigned int	cpt_words(char *s, char c)
{
	unsigned int	i;

	i = 0;
	if (*s == '"')
	{
		i = 1;
		s++;
		while (*s && *s != '"')
			s++;
	}
	if (*s == '\'')
	{
		i = 1;
		s++;
		while (*s && *s != '\'')
			s++;
	}
	if (*s != c && *s && s++)
		i = 1;
	thewhile(&s, &c, &i);
	return (i);
}

static int	util_split(char **rer, unsigned int cpt, char *tp, unsigned int ln)
{
	rer[cpt] = ft_strdup(&tp[ln]);
	if (rer[cpt--] == 0)
	{
		free(tp);
		ft_free_split(rer);
		return (0);
	}
	return (1);
}

static int	inwhile0(int *cpt, char *temp, char c, char **ret)
{
	if (temp[cpt[1]] == c)
		temp[cpt[1]] = '\0';
	else
	{
		if (temp[cpt[1]] == '"')
		{
			cpt[1]--;
			while (temp[cpt[1]] && temp[cpt[1]] != '"')
				cpt[1]--;
		}
		if (temp[cpt[1]] == '\'')
		{
			cpt[1]--;
			while (temp[cpt[1]] && temp[cpt[1]] != '\'')
				cpt[1]--;
		}
		if (cpt[1] == 0 || temp[cpt[1] - 1] == c)
		{
			if (util_split(ret, cpt[0]--, temp, cpt[1]) == 0)
				return (0);
		}
	}
	return (SUCCESS);
}

// cpt 0
// cpt[1] 1
char	**ft_split_protected(char const *s, char c)
{
	unsigned int	cpt[2];
	char			**ret;
	char			*temp;

	if (!s)
		return (0);
	cpt[0] = cpt_words((char *)s, c);
	ret = (char **)malloc((cpt[0] + 1) * sizeof(char *));
	if (ret == 0)
		return (ret);
	ret[cpt[0]--] = 0;
	temp = ft_strdup(s);
	if (!temp)
	{
		free(ret);
		return (0);
	}
	cpt[1] = ft_strlen(temp);
	while (cpt[1]--)
		if (inwhile0((int *)cpt, temp, c, ret) == 0)
			return (0);
	free(temp);
	return (ret);
}
