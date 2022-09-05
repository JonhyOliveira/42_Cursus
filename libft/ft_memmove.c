/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaooliv <joaooliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 11:55:09 by joaooliv          #+#    #+#             */
/*   Updated: 2022/09/04 13:05:58 by joaooliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	byte;

	if (n > 0)
	{
		byte = ((char *)src)[n - 1];
		ft_memmove(dest, src, n - 1);
		((char *)dest)[n - 1] = byte;
	}
	return (dest);
}
