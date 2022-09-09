/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaooliv <joaooliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 17:27:52 by joaooliv          #+#    #+#             */
/*   Updated: 2022/09/09 15:42:35 by joaooliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

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

void	*free_fail(void *to_free)
{
	free(to_free);
	return (0);
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

t_f_options	*parse_format(char *fmt_start, char	**cont_fmt)
{
	t_f_options	*options;
	int			conversion_i;

	if (*fmt_start++ != '%')
		return (0);
	options = (t_options *) malloc(sizeof(t_options));
	if (!options)
		return (0);
	options->arg_i = parse_index(&fmt_start);
	options->padd_char = ' ';
	while (charset_index(*fmt_start, PRINTF_FLAGS) >= 0)
		update_flags(*fmt_start++, options->flags);
	options->padding = 0;
	while (*fmt_start >= '0' && *fmt_start <= '9')
		options->padding = (options->padding * 10) + (*fmt_start++ - '0');
	conversion_i = charset_index(*fmt_start++, PRINTF_CONVERSIONS);
	if (conversion_i < 0 || conversion_i > CONVERSIONS_N)
		return ((t_options *) free_fail(options));
	else
		options->conv = (t_conversion) conversion_i;
	if (cont_fmt)
		*cont_fmt = fmt_start;
	return (options);
}
