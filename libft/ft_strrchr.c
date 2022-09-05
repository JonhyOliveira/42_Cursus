/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaooliv <joaooliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 11:35:40 by joaooliv          #+#    #+#             */
/*   Updated: 2022/09/04 18:14:52 by joaooliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	index;
	char	*found;

	index = 0;
	found = (char *) 0;
	while (s[index])
	{
		if (s[index] == c)
			found = (char *)&s[index];
		index++;
	}
	if (!c)
		found = (char *)&s[index];
	return (found);
}
