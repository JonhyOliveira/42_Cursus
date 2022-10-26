/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaooliv <joaooliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 11:32:57 by joaooliv          #+#    #+#             */
/*   Updated: 2022/10/26 15:56:08 by joaooliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	ft_charset_index(char c, char *charset)
{
	long	index;

	index = 0;
	while (charset && charset[index])
		if (charset[index++] == c)
			return (index - 1);
	return (-1);
}

static int	in_charset(char const c, char const *charset)
{
	return (ft_charset_index((char) c, (char *) charset) >= 0);
}

static size_t	trimmed_size(char const *s1, char const *trimset)
{
	long	count;
	size_t	index;

	count = 0;
	index = 0;
	while (s1[index] && in_charset(s1[index], trimset))
		index++;
	while (s1[index])
	{
		index++;
		count++;
	}
	index--;
	while (in_charset(s1[index], trimset))
	{
		index--;
		count--;
	}
	if (count < 0)
		count = 0;
	return ((size_t)count);
}

char	*ft_strtrim(char const *s1, char const *trimset)
{
	char	*trim;
	char	*trim_it;
	size_t	index;
	size_t	trim_size;
	size_t	trim_index;

	if (!s1 || !trimset)
		return ((char *) 0);
	trim_size = trimmed_size(s1, trimset);
	trim = (char *) malloc(sizeof(char) * (trim_size + 1));
	if (!trim)
		return (trim);
	trim_it = trim;
	index = 0;
	while (s1 && s1[index] && in_charset(s1[index], trimset))
	{
		index++;
	}
	trim_index = 0;
	while (s1 && s1[index + trim_index] && trim_index < trim_size)
	{
		*trim_it++ = s1[index + trim_index++];
	}
	*trim_it = 0;
	return (trim);
}
