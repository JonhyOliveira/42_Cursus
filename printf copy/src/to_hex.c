/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaooliv <joaooliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 19:18:33 by bmiguel-          #+#    #+#             */
/*   Updated: 2022/11/13 19:03:36 by joaooliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internals.h"

static size_t	hex_size(unsigned int n, long precision, bool special)
{
	size_t	size;

	size = nbr_size(n, 16);
	if (precision > (long long) size)
		size = precision;
	if (special && n != 0)
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

/**
 * 	Creates a string representing a given number in hexadecimal following the
 * specified format
 * up	- whether or not to use upper case characters
 * spec - whether or not to use special formatting (0x)
 * prec	- the precision used
*/
static t_str	*n_to_hex_str(unsigned int n, bool up, bool spec, long prec)
{
	t_str			*res;
	char			*to_write;

	res = ft_newstr(hex_size(n, prec, spec));
	if (!res)
		return (0);
	to_write = res->content;
	if (spec && n != 0)
	{
		*to_write++ = '0';
		*to_write++ = 'X' + (32 * (up == true));
	}
	put_hex_rec(n, &to_write, up, prec);
	*to_write = 0;
	return (res);
}

t_str	*to_hex(t_f_options *opts, va_list args)
{
	long			prec;
	unsigned int	n;

	prec = opts->precision;
	n = va_arg(args, unsigned int);
	n_to_hex_str(n, opts->conv == Hhex, opts->flags[hash], prec);
}
