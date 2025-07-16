/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getstr_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgacougn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:47:06 by fgacougn          #+#    #+#             */
/*   Updated: 2023/11/08 17:47:08 by fgacougn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

char	*ft_getpointeur(int *options, void *pointeur, int *nb_char);
char	*ft_getint(int *options, int entier, int *nb_char);
char	*ft_setint(int *cpt, int *nb_char);
char	*ft_get_smolhexa(int *options, unsigned int entier, int *nb_char);
char	*ft_get_bigoldhexa(int *options, unsigned int entier, int *nb_char);
char	*ft_get_unsignedint(int *options, unsigned int entier, int *nb_char);
char	*ft_get_str(int *options, char *str);

char	*ft_getstr_printf(char format, int *optns, va_list *argp, int *nb_cr)
{
	if (format == 'p')
		return (ft_getpointeur(optns, va_arg(*argp, void *), nb_cr));
	else if (format == 'd' || format == 'i')
		return (ft_getint(optns, va_arg(*argp, int), nb_cr));
	else if (format == 'n')
		return (ft_setint(va_arg(*argp, int *), nb_cr));
	else if (format == 'x')
		return (ft_get_smolhexa(optns, va_arg(*argp, unsigned int), nb_cr));
	else if (format == 'X')
		return (ft_get_bigoldhexa(optns, va_arg(*argp, unsigned int), nb_cr));
	else if (format == 'u')
		return (ft_get_unsignedint(optns, va_arg(*argp, unsigned int), nb_cr));
	else if (format == 's')
		return (ft_get_str(optns, va_arg(*argp, char *)));
	return (0);
}
