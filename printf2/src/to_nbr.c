/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_nbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaooliv <joaooliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 17:13:10 by joaooliv          #+#    #+#             */
/*   Updated: 2022/09/23 18:33:28 by joaooliv         ###   ########.fr       */
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

unsigned int	put_dec_prefix(t_list **str, long n, t_f_options *opts)
{
	if (opts->conv != udecimal)
	{
		if (n < 0)
		{
			ft_lstadd_back(str, ft_lstnew('-'));
			return (n * -1);
		}
		else if (opts->flags[plus])
			ft_lstadd_back(str, ft_lstnew('+'));
		else if (opts->flags[space])
			ft_lstadd_back(str, ft_lstnew(' '));
	}
	return (n);
}

static void	put_nbr_rec(unsigned int n, t_list **str, long left)
{
	if (n < 10)
	{
		if (left > 0)
			put_nbr_rec(0, str, left - 1);
		if (left != 0 || n != 0)
			ft_lstadd_back(str, ft_lstnew(n + '0'));
	}
	else
	{
		put_nbr_rec(n / 10, str, left - 1);
		put_nbr_rec(n % 10, str, -1);
	}
}

t_list	*to_dec(t_f_options *opts, va_list args)
{
	t_list	*res;
	long	n;

	res = 0;
	if (opts->conv != udecimal)
		n = va_arg(args, int);
	else
		n = va_arg(args, unsigned int);
	put_nbr_rec(put_dec_prefix(&res, n, opts), &res, opts->precision);
	return (res);
}
