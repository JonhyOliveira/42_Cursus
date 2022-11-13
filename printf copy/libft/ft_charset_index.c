/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charset_index.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaooliv <joaooliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 13:45:31 by joaooliv          #+#    #+#             */
/*   Updated: 2022/09/23 13:47:11 by joaooliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_charset_index(char c, char *charset)
{
	long	index;

	index = 0;
	while (charset && charset[index])
		if (charset[index++] == c)
			return (index - 1);
	return (-1);
}
