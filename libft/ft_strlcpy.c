/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaooliv <joaooliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 17:19:21 by joaooliv          #+#    #+#             */
/*   Updated: 2022/09/04 20:09:54 by joaooliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	unsigned int	src_size;
	unsigned int	curr_size;

	src_size = 0;
	while (src[src_size])
		src_size++;
	if (size != 0)
	{
		curr_size = 0;
		while (src[curr_size] && curr_size < size - 1)
		{
			dest[curr_size] = src[curr_size];
			curr_size++;
		}
		dest[curr_size] = 0;
	}
	return (src_size);
}
