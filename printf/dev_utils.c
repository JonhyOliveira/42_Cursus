/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dev_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaooliv <joaooliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:21:07 by joaooliv          #+#    #+#             */
/*   Updated: 2022/09/21 23:04:04 by joaooliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internals.h"
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

void	print_options(t_f_options *opts)
{
	printf("opts: %p\n", opts);
	if (opts)
	{
		printf("\t- field width: %ld\n", opts->field_width);
		printf("\t- precision: %ld\n", opts->precision);
		printf("\t- argument: %ld\n", opts->arg_i);
		printf("\t- pading character: '%c'\n", opts->padd_char);
		printf("\t- conversion: %s\n", conv_string(opts->conv));
		printf("\t- flags:\n");
		printf("\t\t* #: %s\t* +: %s\n", bool_string(opts->flags[hash]), bool_string(opts->flags[plus]));
		printf("\t\t* -: %s\t* 0: %s\n", bool_string(opts->flags[minus]), bool_string(opts->flags[zero]));
		printf("\t\t* space: %s\n", bool_string(opts->flags[space]));
	}
}

