/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgacougn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:15:04 by fgacougn          #+#    #+#             */
/*   Updated: 2023/11/09 17:15:08 by fgacougn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(char *c);
char	*ft_strdup(const char *s);
char	*ft_get_space(int arrondi, char *retour, long long int entier, char c);
char	*ft_get_ecaps(int arrondi, char *retour, long long int entier, char c);

char	*ft_get_str(int *options, char *str)
{
	char	*retour;

	if (!str && (options[2] < -1 || options[2] > 5))
		retour = ft_strdup("(null)");
	else
		retour = ft_strdup(str);
	if (options[2] > -1 && options[2] < ft_strlen(retour))
		retour[options[2]] = 0;
	if (options[2] == -1 && options[2] < ft_strlen(retour))
		retour[0] = 0;
	if (options[0] > ft_strlen(retour))
		retour = ft_get_space(options[0], retour, ft_strlen(str), ' ');
	if (options[6] > ft_strlen(retour))
		retour = ft_get_ecaps(options[6], retour, ft_strlen(str), ' ');
	return (retour);
}
