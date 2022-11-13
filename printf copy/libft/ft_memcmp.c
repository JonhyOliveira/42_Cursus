/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaooliv <joaooliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 11:56:32 by joaooliv          #+#    #+#             */
/*   Updated: 2022/09/04 18:04:25 by joaooliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *mem1, const void *mem2, size_t n)
{
	unsigned int		index;
	const unsigned char	*s1;
	const unsigned char	*s2;

	if (!n)
		return (0);
	index = 0;
	s1 = (const unsigned char *) mem1;
	s2 = (const unsigned char *) mem2;
	while (s1[index] == s2[index] && index < n - 1)
		index++;
	return (s1[index] - s2[index]);
}
