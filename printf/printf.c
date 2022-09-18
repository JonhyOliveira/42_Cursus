/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaooliv <joaooliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 15:28:10 by joaooliv          #+#    #+#             */
/*   Updated: 2022/09/18 19:59:04 by joaooliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "formats/formats.h"

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

static char	*format(t_f_options *opts, va_list args, size_t index)
{
	va_list	copy;

	va_copy(copy, args);
	while (index-- > 1)
		va_arg(copy, void *);
	if (converters[opts->conv])
		return (converters[opts->conv](opts, args));
	else
		return (0);
}

int ft_printf(const char *fmt, ...) {
	va_list		ap;
	t_f_options	*opts;
	char		*fmt_it;
	char		*str;
	size_t		index;

	index = 0;
	fmt_it = (char *)fmt;
	str = (char *) 0;
	va_start(ap, fmt);
	while (*fmt_it) {
		opts = parse_format(fmt_it, &fmt_it);
		if (opts)
		{
			if (opts->arg_i < 0)
				join_free(&str, format(opts, ap, index++));
			else
				join_free(&str, format(opts, ap, opts->arg_i));
			free(opts);
		}
		else
			join_free(&str, ctos(*fmt_it++));
	}
	va_end(ap);
	put_str(str);
	return (0);
}
