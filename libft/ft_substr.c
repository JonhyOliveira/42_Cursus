/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaooliv <joaooliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 11:31:31 by joaooliv          #+#    #+#             */
/*   Updated: 2022/10/26 17:01:12 by joaooliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	substr_len(char const *s, unsigned int start, size_t len)
{
	size_t	s_length;

	s_length = ft_strlen(s);
	if (start > s_length || !len)
		return (0);
	if (s_length - start < len)
		return (s_length - start);
	return (len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	index;
	size_t	s_length;
	char	*substr;

	if (!s)
		return ((char *) 0);
	s_length = ft_strlen(s);
	len = substr_len(s, start, len);
	substr = malloc(sizeof(char) * (len + 1));
	if (substr)
	{
		index = 0;
		while (s && index < len && start + index < s_length && s[start + index])
		{
			substr[index] = s[start + index];
			index++;
		}
		substr[index] = 0;
	}
	return (substr);
}
