/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaooliv <joaooliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:13:59 by joaooliv          #+#    #+#             */
/*   Updated: 2022/09/14 07:27:09 by joaooliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "formats.h"

static size_t	size(void *mem, t_f_options *opts)
{
	size_t	size;

	size = 0;
	if (opts->conv == character)
		size = 1;
	else if (opts->conv == string)
		while (mem && ((char *)mem)[size])
			size++;
	return (size);
}

char	*to_character(void *mem, t_f_options *opts)
{
	char	*ret;
	char	*ret_it;
	
	ret = (char *) malloc((size(mem, opts) + 1) * sizeof(char));
	if (!ret)
		return (ret);
	ret_it = ret;
	if (opts->conv == character)
	{
		*ret_it++ = (char) mem;
	}
	else if (opts->conv == string)
		while (mem && *((char *)mem))
		{
			*ret_it++ = *((char *) mem);
			mem = ((char *) mem) + 1;
		}
	*ret_it = 0;
//	printf("to_char: '%s' ", ret);
	return (ret);
}
