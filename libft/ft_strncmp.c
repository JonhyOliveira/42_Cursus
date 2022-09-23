/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaooliv <joaooliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 11:38:05 by joaooliv          #+#    #+#             */
/*   Updated: 2022/09/23 13:38:49 by joaooliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	index;

	index = 0;
	if (!n)
		return (0);
	while (s1 && s2 && s1[index] && s1[index] == s2[index] && index < n - 1)
		index++;
	return ((unsigned char) s1[index] - (unsigned char) s2[index]);
}
