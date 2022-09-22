/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pointer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaooliv <joaooliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 16:15:34 by joaooliv          #+#    #+#             */
/*   Updated: 2022/09/19 17:28:01 by joaooliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internals.h"

char	*to_pointer(t_f_options *opts, va_list args)
{
	t_f_options	*tmp;
	char		*res;
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
