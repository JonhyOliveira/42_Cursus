/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaooliv <joaooliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 11:39:47 by joaooliv          #+#    #+#             */
/*   Updated: 2022/09/23 13:37:07 by joaooliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*result;
	size_t	index;

	result = (char *) malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (result)
	{
		index = 0;
		while (s && s[index])
		{
			result[index] = f(index, s[index]);
			index++;
		}
		result[index] = 0;
	}
	return (result);
}
