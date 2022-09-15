/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaooliv <joaooliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 15:22:00 by joaooliv          #+#    #+#             */
/*   Updated: 2022/09/15 17:56:16 by joaooliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

char	*conv_string(t_conversion c)
{
	switch (c)
	{
		case character:
			return "char";
		case string:
			return "string";
		case pointer:
			return "pointer";
		case decimal:
			return "decimal";
		case integer:
			return "int";
		case udecimal:
			return "unsigned decimal";
		case lhex:
			return "low hex";
		case Hhex:
			return "high hex";
		default:
			return "undefined";
	}
}

char	*bool_string(bool b)
{
	if (b)
		return "true";
	else
		return "false";
}

t_f_options	*dup_options(t_f_options *opts)
{
	t_f_options	*res;
	size_t		index;

	res = (t_f_options *) malloc(sizeof(t_f_options));
	if (!res)
		return (res);
	res->field_width = opts->field_width;
	res->precision = opts->precision;
	res->arg_i = opts->arg_i;
	res->padd_char = opts->padd_char;
	res->conv = opts->conv;
	index = -1;
	while (++index < FLAGS_N)
		res->flags[index] = opts->flags[index];
}

void	sanitize_options(t_f_options *opts)
{
	size_t	index;

	if (opts->conv == pointer)
	{
		opts->conv = lhex;
		index = -1;
		while (++index < FLAGS_N)
			if (index == hash)
				opts->flags[index] = true;
			else
				opts->flags[index] = false;
	}
	else
	{
		if (opts->flags[zero] && opts->precision > 0
	}
}

void	print_options(t_f_options *opts)
{
	printf("opts: %p\n", opts);
	if (opts)
	{
		printf("\tfield width: %ld\n", opts->field_width);
		printf("\tprecision: %d\n", opts->precision);
		printf("\targument: %ld\n", opts->arg_i);
		printf("\tpading character: '%c'\n", opts->padd_char);
		printf("\tconversion: %s\n", conv_string(opts->conv));
		printf("flags:\n");
		printf("\t\t#: %s\t+: %s\n", bool_string(opts->flags[hash]), bool_string(opts->flags[plus]));
		printf("\t\t-: %s\t0: %s\n", bool_string(opts->flags[minus]), bool_string(opts->flags[zero]));
		printf("\t\tspace: %s\n", bool_string(opts->flags[space]));
	}
}
