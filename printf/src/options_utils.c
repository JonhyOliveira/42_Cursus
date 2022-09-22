/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaooliv <joaooliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 15:22:00 by joaooliv          #+#    #+#             */
/*   Updated: 2022/09/22 14:24:06 by joaooliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internals.h"

t_f_options	*dup_options(t_f_options *opts)
{
	t_f_options	*res;
	size_t		index;

	res = (t_f_options *) malloc(sizeof(t_f_options));
	if (!res)
		return (res);
	res->field_width = opts->field_width;
	res->precision = opts->precision;
	res->arg_i = opts->arg_i;
	res->padd_char = opts->padd_char;
	res->conv = opts->conv;
	index = -1;
	while (++index < FLAGS_N)
		res->flags[index] = opts->flags[index];
	return (res);
}

void	sanitize_options(t_f_options *opts)
{
	if (opts->flags[zero] && opts->conv >= decimal && opts->conv <= Hhex)
		if (opts->precision > 0)
			opts->flags[zero] = false;
	if (opts->flags[zero] && opts->flags[minus])
		opts->flags[zero] = false;
	if (opts->flags[plus] && opts->flags[space])
		opts->flags[space] = false;
	if (opts->flags[zero])
		opts->padd_char = '0';
}

