/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaooliv <joaooliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 15:28:10 by joaooliv          #+#    #+#             */
/*   Updated: 2022/09/15 15:58:08 by joaooliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "src/formats/formats.h"

void	print_options(t_f_options *opts);

// char to string
static char	*ctos(char c)
{
	char	*str;

	str = (char *) malloc(sizeof(char) * 2);
	str[0] = c;
	str[1] = 0;
	return (str);
}

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
			print_options(opts);
			if (opts->arg_i < 0)
				join_formatted(opts, ap, &str, index++);
			else
				join_formatted(opts, ap, &str, opts->arg_i);
			free(opts);
		}
		else
			join_free(&str, ctos(*fmt_it++));
	}
	va_end(ap);
	put_str(str);
	return (0);
}
