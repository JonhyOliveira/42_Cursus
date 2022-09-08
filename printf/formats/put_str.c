/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaooliv <joaooliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:47:09 by joaooliv          #+#    #+#             */
/*   Updated: 2022/09/08 16:50:00 by joaooliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "put.h"

static size_t	str_len(char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

void	put_str(char *s, t_flags flags, t_options opts)
{
	
}
