/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaooliv <joaooliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 11:39:47 by joaooliv          #+#    #+#             */
/*   Updated: 2022/09/04 13:06:42 by joaooliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	strlen(char const *s)
{
	size_t	count;

	count = 0;
	while (s[count])
		count++;
	return (count);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*result;
	size_t	index;

	result = (char *) malloc(sizeof(char) * (strlen(s) + 1));
	if (result)
	{
		index = 0;
		while (s[index])
		{
			result[index] = f(index, s[index]);
			index++;
		}
		result[index] = 0;
	}
	return (result);
}
