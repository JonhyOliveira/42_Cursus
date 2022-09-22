/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaooliv <joaooliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 17:08:25 by joaooliv          #+#    #+#             */
/*   Updated: 2022/09/22 11:13:27 by joaooliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internals.h"

// joins two strings and frees them
char	*join_free(char *s1, char *s2)
{
	char	*joined;
	char	*j_it;
	char	*aux;

	joined = (char *) malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!joined)
			return (joined);
	j_it = joined;
	aux = s1;
	while (s1 && *s1)
			*j_it++ = *s1++;
	if (aux)
		free(aux);
	aux = s2;
	while (s2 && *s2)
			*j_it++ = *s2++;
	if (aux)
		free(aux);
	*j_it = 0;
	return (joined);
}
// char to string
char	*ctos(char c)
{
	char	*str;

	str = (char *) malloc(sizeof(char) * 2);
	str[0] = c;
	str[1] = 0;
	return (str);
}
