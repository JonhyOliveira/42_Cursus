/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaooliv <joaooliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 12:02:57 by joaooliv          #+#    #+#             */
/*   Updated: 2022/09/04 13:05:35 by joaooliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *mem, int c, size_t n)
{
	const unsigned char	*str;
	size_t				index;

	str = (const unsigned char *) mem;
	index = 0;
	while (index < n)
	{
		if (str[index] == (unsigned char) c)
			return ((void *)&str[index]);
		index++;
	}
	return ((void *) 0);
}
