/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaooliv <joaooliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 17:27:52 by joaooliv          #+#    #+#             */
/*   Updated: 2022/09/08 18:45:53 by joaooliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	charset_index(char c, char *charset)
{
	size_t	index;

	index = 0;
	while (charset[index])
		if (charset[index++] == c)
			return (index - 1);
	return (-1);
}

static int	update_flags(char flag, t_flags flags)
{
	int	flag_i;

	flag_i = -1;
	while (++flag_i < FLAGS_N)
		if (!flags[flag_i] && PRINTF_FLAGS[flag_i] == flag)
		{
			flags[flag_i] = true;
			return (1);
		}
	return (0);
}

void	*free_fail(void *to_free)
{
	free(to_free);
	return (0);
}

#include <stdio.h>

t_options	*parse_format(char *fmt_start)
{
	t_options	*options;
	int			conversion_i;

	printf("%s\n", fmt_start);
	if (*fmt_start++ != '%')
		return (0);	
	options = (t_options *) malloc(sizeof(t_options));
	if (!options)
		return (0);
	printf("OK");
	while (charset_index(*fmt_start, PRINTF_FLAGS) > 0)
		if (!update_flags(*fmt_start++, options->flags))
			return ((t_options *) free_fail(options));
	options->padding = 0;
	while (*fmt_start >= '0' && *fmt_start <= '9')
		options->padding = (options->padding * 10) + (*fmt_start++ - '0');
	printf("OK");
	conversion_i = charset_index(*fmt_start, PRINTF_CONVERSIONS);
	if (conversion_i < 0 || conversion_i > CONVERSIONS_N)
		return ((t_options *) free_fail(options));
	else
		options->conv = (t_conversion) conversion_i;
	return (options);	
}
