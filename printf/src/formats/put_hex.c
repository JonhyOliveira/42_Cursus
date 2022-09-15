/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_hex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiguel- <bmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 19:18:33 by bmiguel-          #+#    #+#             */
/*   Updated: 2022/09/14 19:41:31 by joaooliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "formats.h"


static size_t	hex_size(unsigned int n, t_f_options *opts)
{
	size_t	size;

	size = nbr_size(n, 16);
	if (opts->flags[hash])
		size += 2;
	return (size);
}

static char		to_hex_char(unsigned int n, bool upper)
{
	if (n > 16)
		return ('!');
	else if (n > 10)
	{
		if (upper)
			return (n - 10 + 'A');
		else
			return (n - 10 + 'a');
	}
	else
		return (n + '0');
}

static void		put_hex_prefix(char **str_ptr, bool upper)
{
	char	*it;

	it = *str_ptr;
	*it++ = '0';
	if (upper)
		*it++ = 'X';
	else
		*it++ = 'x';
	*str_ptr = it;
}

static void		put_hex_rec(unsigned int n, char **str_ptr, bool upper)
{
	if (n < 16)
		*(*str_ptr)++ = to_hex_char(n, upper);
	else
	{
		put_hex_rec(n / 16, str_ptr, upper);
		put_hex_rec(n % 16, str_ptr, upper);
	}
}

char			*to_hex(unsigned int n, t_f_options *opts)
{
	char	*res;
	char	*res_it;

	res = (char *) malloc(sizeof(char) * (hex_size(n, opts) + 1));
	if (!res)
		return (res);
	res_it = res;
	if (opts->flags[hash])
		put_hex_prefix(&res_it, opts->conv == Hhex);
	put_hex_rec(n, &res_it, opts->conv == Hhex);
	*res_it = 0;
	return (res);
}
