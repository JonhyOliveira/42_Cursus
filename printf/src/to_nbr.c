/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_nbr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaooliv <joaooliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 17:13:10 by joaooliv          #+#    #+#             */
/*   Updated: 2022/09/22 14:51:24 by joaooliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internals.h"

static size_t	dec_size(int n, t_f_options *opts)
{
	size_t	size;

	size = nbr_size(n, 10);
	if (opts->precision > (long long) size)
		size = opts->precision;
	if (opts->conv != udecimal) 
		if (opts->flags[plus] || opts->flags[space] || n < 0)
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

char	*to_dec(t_f_options *opts, va_list args)
{
	char	*res;
	char	*res_it;
	long	n;

	if (opts->conv != udecimal)
		n = va_arg(args, int);
	else
		n = va_arg(args, unsigned int);
	res = (char *) malloc(sizeof(char) * (dec_size(n, opts) + 1));
	if (!res)
		return (res);
	res_it = res;
	put_nbr_rec(put_dec_prefix(&res_it, n, opts), &res_it, opts->precision);
	*res_it = 0;
	return (res);
}
