/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaooliv <joaooliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 19:47:19 by joaooliv          #+#    #+#             */
/*   Updated: 2022/09/18 19:47:30 by joaooliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

// joins two strings and frees them
char	*join_free(char **s1_ptr, char *s2)
{
	char	*joined;
	char	*j_it;
	char	*s1_it;
	char	*s2_it;

	joined = (char *) malloc(sizeof(char) * (str_len(*s1_ptr) + str_len(s2) + 1));
	if (!joined)
			return (joined);
	j_it = joined;
	s1_it = *s1_ptr;
	s2_it = s2;
	while (s1_it && *s1_it)
			*j_it++ = *s1_it++;
	while (s2_it && *s2_it)
			*j_it++ = *s2_it++;
	*j_it = 0;
	if (s1_ptr)
	{
		free(*s1_ptr);
		*s1_ptr = joined;
	}
	free(s2);
	return (joined);
}

