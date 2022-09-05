/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaooliv <joaooliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 12:10:32 by joaooliv          #+#    #+#             */
/*   Updated: 2022/09/04 14:17:43 by joaooliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void		*ret;
	size_t		alloc_size;

	ret = (void *) 0;
	if (nmemb && size && nmemb <= INT_MAX / size)
	{
		alloc_size = nmemb * size;
		ret = (void *)malloc(alloc_size);
		if (ret)
			ft_bzero(ret, alloc_size);
	}
	return (ret);
}
