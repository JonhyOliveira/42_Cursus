/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaooliv <joaooliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 11:32:57 by joaooliv          #+#    #+#             */
/*   Updated: 2022/09/23 13:44:52 by joaooliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	in_charset(char const c, char const *charset)
{
	int		found;
	size_t	index;

	found = 0;
	index = 0;
	while (!found && charset[index])
		found = (c == charset[index++]);
	return (found);
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
