/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaooliv <joaooliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 11:45:38 by joaooliv          #+#    #+#             */
/*   Updated: 2022/09/23 13:32:40 by joaooliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	index;

	index = 0;
	while (s && s[index])
	{
		if (s[index] == c)
			return ((char *)&s[index]);
		index++;
	}
	if (!c)
		return ((char *)&s[index]);
	else
		return ((char *) 0);
}
