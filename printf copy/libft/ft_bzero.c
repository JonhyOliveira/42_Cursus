/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaooliv <joaooliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 12:11:56 by joaooliv          #+#    #+#             */
/*   Updated: 2022/09/04 13:41:28 by joaooliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *mem, size_t n)
{
	char	*mem_it;

	mem_it = (char *) mem;
	while (mem_it - (char *)mem < (long int )n)
		*mem_it++ = (char) 0;
}
