/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaooliv <joaooliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 11:54:30 by joaooliv          #+#    #+#             */
/*   Updated: 2022/09/04 13:40:22 by joaooliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *mem, int c, size_t n)
{
	char	*mem_it;

	mem_it = (char *)mem;
	while (mem_it - (char *)mem < (long int)n)
		*mem_it++ = (char) c;
	return (mem);
}
