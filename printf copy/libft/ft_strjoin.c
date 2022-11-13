/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaooliv <joaooliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 11:41:11 by joaooliv          #+#    #+#             */
/*   Updated: 2022/10/26 15:58:28 by joaooliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	char	*join_it;
	size_t	index;

	if (!s1 || !s2)
		return ((char *) 0);
	join = (char *) malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (join)
	{
		join_it = join;
		index = 0;
		while (s1 && s1[index])
			*join_it++ = s1[index++];
		index = 0;
		while (s2 && s2[index])
			*join_it++ = s2[index++];
		*join_it = 0;
	}
	return (join);
}
