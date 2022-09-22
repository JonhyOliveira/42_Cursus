/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_letters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaooliv <joaooliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:13:59 by joaooliv          #+#    #+#             */
/*   Updated: 2022/09/22 15:01:40 by joaooliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internals.h"

char	*to_character(t_f_options *opts, va_list args)
{
	(void) opts;
	return (ctos(va_arg(args, int)));
}

char	*to_str(t_f_options *opts, va_list args)
{
	(void) opts;
	char	*str_rep;
	char	*tmp;

	str_rep = ft_strdup((char *) va_arg(args, void *));
	if ((long long) ft_strlen(str_rep) > opts->precision && opts->precision > 0)
	{
		tmp = str_rep;
		str_rep = ft_substr(str_rep, 0, opts->precision);
		free(tmp);
	}
	return (str_rep);
}
