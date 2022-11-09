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

static void	put_hex_rec(unsigned int n, t_list **str, bool upper, long left)
{
	if (n < 16)
	{
		if (left > 0)
			put_hex_rec(0, str, upper, left - 1);
		if (left != 0 || n != 0)
			ft_lstadd_back(str, ft_lstnew(to_hex_char(n, upper)));
	}
	else
	{
		put_hex_rec(n / 16, str, upper, left - 1);
		put_hex_rec(n % 16, str, upper, -1);
	}
}

t_list	*to_hex(t_f_options *opts, va_list args)
{
	t_list			*res;
	char			*res_it;
	unsigned int	n;

	res = 0;
	n = va_arg(args, unsigned int);
	if (opts->flags[hash] && n != 0)
	{
		ft_lstadd_back(&res, ft_lstnew('0'));
		if (opts->conv == lhex)
			ft_lstadd_back(&res, ft_lstnew('x'));
		else
			ft_lstadd_back(&res, ft_lstnew('X'));
	}
	put_hex_rec(n, &res, opts->conv == Hhex, opts->precision);
	return (res);
}
