/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaooliv <joaooliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 15:28:10 by joaooliv          #+#    #+#             */
/*   Updated: 2022/09/22 15:41:03 by joaooliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "internals.h"

void	print_options(t_f_options *opts);

static void	put_str(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	*free_fail(void *to_free)
{
	free(to_free);
	return (0);
}

static char *(*converters[CONVERSIONS_N])(t_f_options *,va_list) =
{
	&to_character,
	&to_str,
	&to_pointer,
	&to_dec,
	&to_dec,
	&to_dec,
	&to_hex,
	&to_hex
};

static char	*do_padding(char *str, t_f_options *opts)
{
	size_t	str_len;
	char	*padd_str;

	str_len = ft_strlen(str);
	padd_str = 0;
	if ((long long) str_len < opts->field_width && opts->field_width > 0)
	{
		padd_str = (char *) malloc(sizeof(char) * (opts->field_width - str_len + 1));
		if (!padd_str)
			return (str);
		ft_memset(padd_str, opts->padd_char, opts->field_width - str_len);
		padd_str[opts->field_width - str_len] = 0;
	}
	if (opts->flags[minus])
		return (join_free(str, padd_str));
	else
		return (join_free(padd_str, str));
	
}

#include <stdio.h>
static char	*format(t_f_options *opts, va_list args, size_t index)
{
	va_list	copy;

	va_copy(copy, args);
	while (index-- > 1)
		va_arg(copy, void *);
	if (converters[opts->conv])
		return (do_padding(converters[opts->conv](opts, copy), opts));
	else
		return (0);
}

int		ft_printf(const char *fmt, ...)
{
	va_list		ap;
	t_f_options	*opts;
	char		*fmt_it;
	char		*str;
	size_t		index;

	index = 1;
	fmt_it = (char *)fmt;
	str = (char *) 0;
	va_start(ap, fmt);
	while (*fmt_it) {
		opts = parse_format(fmt_it, &fmt_it);
		if (opts)
		{
			if (opts->arg_i <= 0)
				str = join_free(str, format(opts, ap, index++));
			else
				str = join_free(str, format(opts, ap, opts->arg_i));
			free(opts);
		}
		else
			str = join_free(str, ctos(*fmt_it++));
	}
	va_end(ap);
	put_str(str);
	return (0);
}
