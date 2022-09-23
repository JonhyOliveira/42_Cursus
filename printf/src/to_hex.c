/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiguel- <bmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 19:18:33 by bmiguel-          #+#    #+#             */
/*   Updated: 2022/09/23 19:04:19 by joaooliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internals.h"

static size_t	hex_size(unsigned int n, t_f_options *opts)
{
	size_t	size;

	size = nbr_size(n, 16);
	if (opts->precision > (long long) size)
		size = opts->precision;
	if (opts->flags[hash] && n != 0)
		size += 2;
	return (size);
}

static char	to_hex_char(unsigned int n, bool upper)
{
	if (n > 16)
		return ('!');
	else if (n >= 10)
	{
		if (upper)
			return (n - 10 + 'A');
		else
			return (n - 10 + 'a');
	}
	else
		return (n + '0');
}

static void	put_hex_rec(unsigned int n, char **str_ptr, bool upper, long left)
{
	if (n < 16)
	{
		if (left > 0)
			put_hex_rec(0, str_ptr, upper, left - 1);
		if (left != 0 || n != 0)
			*(*str_ptr)++ = to_hex_char(n, upper);
	}
	else
	{
		put_hex_rec(n / 16, str_ptr, upper, left - 1);
		put_hex_rec(n % 16, str_ptr, upper, -1);
	}
}

char	*to_hex(t_f_options *opts, va_list args)
{
	char			*res;
	char			*res_it;
	unsigned int	n;

	n = va_arg(args, unsigned int);
	res = (char *) malloc(sizeof(char) * (hex_size(n, opts) + 1));
	if (!res)
		return (res);
	res_it = res;
	if (opts->flags[hash] && n != 0)
	{
		*res_it++ = '0';
		if (opts->conv == lhex)
			*res_it++ = 'x';
		else
			*res_it++ = 'X';
	}
	put_hex_rec(n, &res_it, opts->conv == Hhex, opts->precision);
	*res_it = 0;
	return (res);
}
