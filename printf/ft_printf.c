/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaooliv <joaooliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 15:28:10 by joaooliv          #+#    #+#             */
/*   Updated: 2022/09/23 19:08:04 by joaooliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "internals.h"

void	print_options(t_f_options *opts);

static char	*do_padding(char *str, t_f_options *opts)
{
	size_t	padd_len;
	char	*padd_str;

	padd_len = opts->field_width - ft_strlen(str);
	padd_str = 0;
	if (padd_len > 0 && opts->field_width > 0)
	{
		padd_str = (char *) malloc(sizeof(char) * (padd_len + 1));
		if (!padd_str)
			return (str);
		ft_memset(padd_str, opts->padd_char, padd_len);
		padd_str[padd_len] = 0;
	}
	if (opts->flags[minus])
		return (join_free(str, padd_str));
	else
		return (join_free(padd_str, str));
}

static char	*format(t_f_options *opts, va_list args, size_t index)
{
	va_list		copy;
	static char	*(*converters[CONVERSIONS_N])(t_f_options *, va_list);

	converters[null] = &to_perc;
	converters[character] = &to_character;
	converters[string] = &to_str;
	converters[pointer] = &to_pointer;
	converters[decimal] = &to_dec;
	converters[integer] = &to_dec;
	converters[udecimal] = &to_dec;
	converters[lhex] = &to_hex;
	converters[Hhex] = &to_hex;
	va_copy(copy, args);
	while (index-- > 1)
		va_arg(copy, void *);
	if (converters[opts->conv])
		return (do_padding(converters[opts->conv](opts, copy), opts));
	else
		return (0);
}

// because everyone hates norminette
static void	loopdy_loop(char **fmt_it, size_t *index, va_list args, char **str)
{
	t_f_options	*opts;
	opts = parse_format(*fmt_it, fmt_it);
	if (opts)
	{
		if (opts->arg_i <= 0)
			*str = join_free(*str, format(opts, args, (*index)++));
		else
			*str = join_free(*str, format(opts, args, opts->arg_i));
		free(opts);
	}
	else
		*str = join_free(*str, ctos(*(*fmt_it)++));
}

int	ft_printf(const char *fmt, ...)
{
	va_list		ap;
	char		*fmt_it;
	char		*str;
	size_t		index;

	index = 1;
	fmt_it = (char *)fmt;
	str = (char *) 0;
	va_start(ap, fmt);
	while (*fmt_it)
		loopdy_loop(&fmt_it, &index, ap, &str);
	ft_putstr_fd(str, 1);
	return (0);
}
