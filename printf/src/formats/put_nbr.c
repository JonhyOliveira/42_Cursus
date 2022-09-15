/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_nbr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaooliv <joaooliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 17:13:10 by joaooliv          #+#    #+#             */
/*   Updated: 2022/09/14 19:37:41 by joaooliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "formats.h"

static size_t	dec_size(int n, t_f_options *opts)
{
	size_t	size;

	size = nbr_size(n, 10);
	if (opts->conv != udecimal && (opts->flags[plus] || opts->flags[space]))
		size++;
	return (size);
}

static void	put_dec_prefix(char **str_ptr, int *n, t_f_options *opts)
{
	if (opts->conv != udecimal)
	{
		if (*n < 0)
		{
			*(*str_ptr)++ = '-';
			*n *= -1;
		}
		else if (opts->flags[plus])
			*(*str_ptr)++ = '+';
		else if (opts->flags[space])
			*(*str_ptr)++ = ' ';
	}
}

static void	put_nbr_rec(unsigned int n, char **str_ptr)
{
	if (n < 10)
		*(*str_ptr)++ = n + '0';
	else
	{
		put_nbr_rec(n / 10, str_ptr);
		put_nbr_rec(n % 10, str_ptr);
	}
}

char	*to_dec(int n, t_f_options *opts)
{
	char	*res;
	char	*res_it;

	res = (char *) malloc(sizeof(char) * (dec_size(n, opts) + 1));
	if (!res)
		return (res);
	res_it = res;
	put_dec_prefix(&res_it, &n, opts);
	put_nbr_rec(n, &res_it);
	*res_it = 0;
	return (res);
}
