/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaooliv <joaooliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 11:40:58 by joaooliv          #+#    #+#             */
/*   Updated: 2022/10/26 15:42:53 by joaooliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_l;
	size_t	index;

	if (!dest && size == 0)
		return (0);
	dest_l = ft_strlen(dest);
	if (size > 0 && dest_l < size - 1)
	{
		index = 0;
		while (src[index] && dest_l + index < size - 1)
		{
			dest[dest_l + index] = src[index];
			index++;
		}
		dest[dest_l + index] = 0;
	}
	if (dest_l >= size)
		dest_l = size;
	return (dest_l + ft_strlen(src));
}
