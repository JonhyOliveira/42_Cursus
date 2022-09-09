/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaooliv <joaooliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 15:28:10 by joaooliv          #+#    #+#             */
/*   Updated: 2022/09/09 15:45:01 by joaooliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "formats/formats.h"

static size_t	max_index(char *fmt)
{
	size_t	counter;
	size_t	max;
	t_f_options	*opts;

	counter = 0;
	max = 0;
	while (*fmt)
	{
		opts = parse_format(fmt, &fmt);
		if (opts)
		{
			if (opts->arg_i >= 0)
			{
				if (opts->arg_i > max)
					max = opts->arg_i;
			}
			else
				counter++;
		}
		else
			fmt++;
	}
	if (counter > max)
		max = counter;
	printf("counter: %ld\n", counter);
	return (max);
}

int		ft_printf(const char *fmt, ...)
{
	printf("%ld\n", max_index(fmt));
}
