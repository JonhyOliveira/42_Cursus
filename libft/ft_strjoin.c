/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaooliv <joaooliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 11:41:11 by joaooliv          #+#    #+#             */
/*   Updated: 2022/09/04 13:06:30 by joaooliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (s[count])
		count++;
	return (count);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_size;
	char	*join;
	char	*join_it;
	size_t	index;

	s1_size = strlen(s1);
	join = (char *) malloc(sizeof(char) * (s1_size + strlen(s2) + 1));
	if (join)
	{
		join_it = join;
		index = 0;
		while (s1[index])
			*join_it++ = s1[index++];
		index = 0;
		while (s2[index])
			*join_it++ = s2[index++];
		*join_it = 0;
	}
	return (join);
}
