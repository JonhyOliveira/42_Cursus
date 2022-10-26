/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaooliv <joaooliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 11:55:09 by joaooliv          #+#    #+#             */
/*   Updated: 2022/10/26 15:36:38 by joaooliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!dest && !src && n > 0)
		return ((void *) 0);
	if (src < dest)
	{
		i = n;
		while (i-- > 0)
			*((char *)dest + i) = *((const char *)src + i);
	}
	else
	{
		i = -1;
		while (++i < n)
			*((char *)dest + i) = *((const char *)src + i);
	}
	return (dest);
}
