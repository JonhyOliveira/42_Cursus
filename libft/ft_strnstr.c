/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaooliv <joaooliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 11:36:38 by joaooliv          #+#    #+#             */
/*   Updated: 2022/10/26 15:57:38 by joaooliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	haystack_i;
	size_t	needle_i;

	haystack_i = 0;
	needle_i = 0;
	if (haystack || len != 0)
	{
		while (haystack_i + needle_i <= len)
		{
			if (!needle[needle_i])
				return ((char *)&haystack[haystack_i]);
			if (!haystack[haystack_i + needle_i])
				break ;
			if (haystack[haystack_i + needle_i] == needle[needle_i])
				needle_i++;
			else
			{
				needle_i = 0;
				haystack_i++;
			}
		}
	}
	return ((char *) 0);
}
