/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_others.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaooliv <joaooliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:13:59 by joaooliv          #+#    #+#             */
/*   Updated: 2022/09/23 19:10:06 by joaooliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internals.h"

char	*to_character(t_f_options *opts, va_list args)
{
	(void) opts;
	return (ctos(va_arg(args, int)));
}

t_list	*to_str(t_f_options *opts, va_list args)
{
	char	*str;
	size_t	index;
	t_list	*res;

	(void) opts;
	str = (char *) va_arg(args, void *);
	res = 0;
	index = 0;
	while (str && str[index] && (opts->precision <= 0 || index > opts->precision))
		ft_lstadd_back(&res, ft_lstnew(str[index++]));
	return (res);
}

t_list	*to_pointer(t_f_options *opts, va_list args)
{
	t_f_options	*tmp;
	t_list		*res;
	size_t		index;

	tmp = dup_options(opts);
	res = 0;
	if (!tmp)
		return (res);
	tmp->conv = lhex;
	index = -1;
	while (++index < FLAGS_N)
		tmp->flags[index] = false;
	tmp->flags[hash] = true;
	res = to_hex(tmp, args);
	free(tmp);
	return (res);
}

t_list	*to_perc(t_f_options *opts, va_list args)
{
	(void) opts;
	(void) args;
	return (ft_lstnew('%'));
}
