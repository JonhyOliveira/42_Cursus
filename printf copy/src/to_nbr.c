/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_nbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaooliv <joaooliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 17:13:10 by joaooliv          #+#    #+#             */
/*   Updated: 2022/11/13 19:11:02 by joaooliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internals.h"

static size_t	dec_size(int n, long precision, bool is_sign, bool pos_pref)
{
	size_t	size;

	size = nbr_size(n, 10);
	if (precision > (long long) size)
		size = precision;
	if (is_sign && (pos_pref || n < 0))
		size++;
	return (size);
}

unsigned int	put_dec_prefix(char **str_ptr, long n, t_f_options *opts)
{
	if (opts->conv != udecimal)
	{
		if (n < 0)
		{
			*(*str_ptr)++ = '-';
			return (n * -1);
		}
		else if (opts->flags[plus])
			*(*str_ptr)++ = '+';
		else if (opts->flags[space])
			*(*str_ptr)++ = ' ';
	}
	return (n);
}

static void	put_nbr_rec(unsigned int n, char **str_ptr, long left)
{
	if (n < 10)
	{
		if (left > 0)
			put_nbr_rec(0, str_ptr, left - 1);
		if (left != 0 || n != 0)
			*(*str_ptr)++ = n + '0';
	}
	else
	{
		put_nbr_rec(n / 10, str_ptr, left - 1);
		put_nbr_rec(n % 10, str_ptr, -1);
	}
}

/**
 * prec		- the used precision
 * is_sign	- whether or not the number is to be interpreted as signed
 * pos_pref	- the prefix to add if the number is positive, or 0 if none
*/
static t_str	*n_to_dec_str(long n, long prec, bool is_sign, char pos_pref)
{
	t_str	*res;
	char	*to_write;

	res = ft_newstr(dec_size(n, prec, is_sign, pos_pref != 0));
	if (!res)
		return (0);
	to_write = res->content;
	if (is_sign)
	{
		if (n < 0)
		{
			*to_write++ = '-';
			n *= -1;
		}
		else if (pos_pref != 0)
			*to_write++ = pos_pref;
	}
	put_nbr_rec(n, &to_write, prec);
	*to_write = 0;
	return (res);
}

t_str	*to_dec(t_f_options *opts, va_list args)
{
	char	pos_pref;
	long	n;

	if (opts->conv != udecimal)
		n = va_arg(args, int);
	else
		n = va_arg(args, unsigned int);
	pos_pref = 0;
	if (opts->flags[plus])
		pos_pref = '+';
	else if (opts->flags[space])
		pos_pref = ' ';
	return (n_to_dec_str(n, opts->precision, opts->conv != udecimal, pos_pref));
}
