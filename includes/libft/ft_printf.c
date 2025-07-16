/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgacougn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:31:03 by fgacougn          #+#    #+#             */
/*   Updated: 2023/11/09 16:31:06 by fgacougn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

void	ft_putchar_fd(char c, int fd);
int		ft_is_in(char *charset, char c);
void	*ft_memset(void *s, int c, size_t n);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *c);

static void	ft_putstr_printf(char f, int *o, va_list *argp, int *nb_cr)
{
	char			*to_put;

	if (f == 'c')
	{
		while (o[6]-- > 1 && (*nb_cr)++ > -2)
			ft_putchar_fd(' ', 1);
		ft_putchar_fd(va_arg(*argp, int), 1);
		while (o[0]-- > 1 && (*nb_cr)++ > -2)
			ft_putchar_fd(' ', 1);
		*nb_cr += 1;
	}
	else if (f == '%' && (*nb_cr)++ > -2)
		ft_putchar_fd('%', 1);
	else
	{
		to_put = ft_getstr_printf(f, o, argp, nb_cr);
		if (to_put)
		{
			ft_putstr_fd(to_put, 1);
			*nb_cr += ft_strlen(to_put);
			free(to_put);
		}
	}
}

static void	cpt_opt(int *opt, int *optons, const char **format)
{
	int	memopt;

	memopt = *opt;
	if (*opt > 5)
	{
		(*format)--;
		memopt = 6;
	}
	optons[memopt] = -1;
	*opt = ft_is_in(OPTIONS, **format);
	while ((*opt == 1 || *opt == -1 || *opt > 5)
		&& **format <= '9' && **format >= '0')
	{
		if (optons[memopt] == -1)
			optons[memopt] = 0;
		optons[memopt] *= 10;
		optons[memopt] += **format - '0';
		(*format)++;
		*opt = ft_is_in(OPTIONS, **format);
	}
}

static void	parsing(const char **format, int *optons, va_list *argp, int *i)
{
	int		opt;

	opt = ft_is_in(OPTIONS, **format);
	while (opt != -1)
	{
		(*format)++;
		if (opt == 1 || opt == 2 || opt == 0 || opt > 5)
		{
			cpt_opt(&opt, optons, format);
		}
		else
		{
			optons[opt] = 1;
			opt = ft_is_in(OPTIONS, **format);
		}
	}
	opt = ft_is_in(TYPES, **format);
	if (opt != -1)
		ft_putstr_printf(**format, optons, argp, i);
}

int	ft_printf(const char *format, ...)
{
	va_list			argp;
	int				optons[NB_OPTIONS];
	int				i;

	if (!format)
		return (-1);
	ft_memset(optons, -2, NB_OPTIONS * sizeof(int));
	va_start(argp, format);
	i = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format ++;
			parsing(&format, optons, &argp, &i);
			ft_memset(optons, -2, NB_OPTIONS * sizeof(int));
			format ++;
		}
		else
		{
			ft_putchar_fd(*(format ++), 1);
			i ++;
		}
	}
	return (i);
}
