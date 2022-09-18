/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaooliv <joaooliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 17:08:25 by joaooliv          #+#    #+#             */
/*   Updated: 2022/09/16 14:40:38 by joaooliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

// char to string
char	*ctos(char c)
{
	char	*str;

	str = (char *) malloc(sizeof(char) * 2);
	str[0] = c;
	str[1] = 0;
	return (str);
}

size_t	str_len(char *str)
{
	size_t	len;

	len = 0;
	while (str && str[len])
		len++;
	return (len);
}
