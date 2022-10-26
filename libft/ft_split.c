/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaooliv <joaooliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 11:46:24 by joaooliv          #+#    #+#             */
/*   Updated: 2022/10/26 15:53:55 by joaooliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static size_t	split_counter(char const *s, char c)
{
	size_t	splits_counter;
	size_t	index;

	splits_counter = 0;
	index = 0;
	while (s && s[index])
	{
		while (c && s[index] == c)
			index++;
		while (s[index] && s[index] != c)
			index++;
		if (c && s[index] == c)
			splits_counter++;
	}
	if (index > 0 && s[index - 1] != c)
		splits_counter++;
	return (splits_counter);
}

static char	*one_split(char const *s, char c, size_t *continue_ptr)
{
	size_t	index;
	size_t	index2;
	char	*split_result;
	char	*split_res_it;

	index = 0;
	index2 = 0;
	while (s[index] && s[index] == c)
		index++;
	while (s[index + index2] && s[index + index2] != c)
		index2++;
	split_result = (char *) malloc(sizeof(char) * (index2 + 1));
	if (!split_result)
		return ((char *) 0);
	index = 0;
	index2 = 0;
	split_res_it = split_result;
	while (s[index] && s[index] == c)
		index++;
	while (s[index + index2] && s[index + index2] != c)
		*split_res_it++ = s[index + index2++];
	*split_res_it = 0;
	if (continue_ptr)
		*continue_ptr += index + index2;
	return (split_result);
}

static char	**split_free(char **split)
{
	char	*split_str;

	split_str = *split;
	while (split_str)
		free(split_str++);
	free(split);
	return ((char **) 0);
}

char	**ft_split(char const *s, char c)
{
	size_t	split_index;
	size_t	str_index;
	size_t	splits;
	char	**split;

	splits = split_counter(s, c);
	split = (char **) malloc(sizeof(char *) * (splits + 1));
	if (split)
	{
		split_index = 0;
		str_index = 0;
		while (split_index < splits)
		{
			split[split_index] = one_split(&s[str_index], c, &str_index);
			if (!split[split_index])
				return (split_free(split));
			split_index++;
		}
		split[split_index] = (char *) 0;
	}
	return (split);
}
