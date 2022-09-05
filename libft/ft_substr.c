/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaooliv <joaooliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 11:31:31 by joaooliv          #+#    #+#             */
/*   Updated: 2022/09/04 20:55:04 by joaooliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	index;
	size_t	s_length;
	char	*substr;

	s_length = ft_strlen(s);
	substr = malloc(sizeof(char) * (len + 1));
	if (substr && start < s_length)
	{
		index = 0;
		while (s[start + index] && index < len && start + index < s_length)
		{
			substr[index] = s[start + index];
			index++;
		}
		substr[index] = 0;
	}
	return (substr);
}
