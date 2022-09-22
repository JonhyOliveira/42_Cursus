/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaooliv <joaooliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 17:27:52 by joaooliv          #+#    #+#             */
/*   Updated: 2022/09/22 15:32:26 by joaooliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internals.h"

long	charset_index(char c, char *charset)
{
	long	index;

	index = 0;
	while (charset[index])
		if (charset[index++] == c)
			return (index - 1);
	return (-1);
}

static int	update_flags(char flag, t_flags flags)
{
	int	flag_i;

	flag_i = charset_index(flag, PRINTF_FLAGS);
	if (flag_i >= 0 && flag_i < FLAGS_N && flags[flag_i] != true)
		flags[flag_i] = true;
	else
		return (0);
	return (1);
}

// parses "[0-9]*$" regex
// returns parsed number if successfull, -1 otherwise 
static size_t	parse_index(char **fmt_ptr)
{
	char	*fmt;
	size_t	index;

	if (!fmt_ptr)
		return (-1);
	fmt = *fmt_ptr;
	index = 0;
	while (*fmt >= '0' && *fmt <= '9')
		index = (index * 10) + *fmt++ - '0';
	if (*fmt++ != '$')
		return (-1);
	*fmt_ptr = fmt;
	return (index);
}

static void	parse_width_n_precision(char **fmt_ptr, t_f_options *opts)
{
	char	*fmt;

	opts->field_width = -1;
	opts->precision = -1;
	fmt = *fmt_ptr;
	if (*fmt >= '0' && *fmt <= '9')
		opts->field_width = 0;
	while (*fmt >= '0' && *fmt <= '9')
		opts->field_width = (opts->field_width * 10) + (*fmt++ - '0');
	if (*fmt == '.')
	{
		fmt++;
		opts->precision = 0;
		while (*fmt >= '0' && *fmt <= '9')
			opts->precision = (opts->precision * 10) + (*fmt++ - '0');
	}
	*fmt_ptr = fmt;
}

t_f_options	*parse_format(char *fmt_start, char	**cont_fmt)
{
	t_f_options	*options;
	int			index;

	if (*fmt_start++ != '%')
		return (0);
	options = (t_f_options *) malloc(sizeof(t_f_options));
	if (!options)
		return (0);
	options->arg_i = parse_index(&fmt_start);
	options->padd_char = ' ';
	index = 0;
	while (index < FLAGS_N)
		options->flags[index++] = false;
	while (charset_index(*fmt_start, PRINTF_FLAGS) >= 0)
		update_flags(*fmt_start++, options->flags);
	parse_width_n_precision(&fmt_start, options);
	index = charset_index(*fmt_start++, PRINTF_CONVERSIONS);
	if (index < 0 || index > CONVERSIONS_N)
		return ((t_f_options *) free_fail(options));
	else
		options->conv = (t_conversion) index;
	if (cont_fmt)
		*cont_fmt = fmt_start;
	return (options);
}
