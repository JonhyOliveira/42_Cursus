/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaooliv <joaooliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:17:08 by joaooliv          #+#    #+#             */
/*   Updated: 2022/09/08 18:33:28 by joaooliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

#include <stdbool.h>
#include <stdlib.h>

#define PRINTF_FLAGS "#+-0 "
#define FLAGS_N 5

#define PRINTF_CONVERSIONS "cspdiuxX"
#define CONVERSIONS_N 8

typedef enum	e_flag
{
	hash,
	plus,
	minus,
	zero,
	space
}	t_flag;

typedef enum	e_conversion
{ 
	character,
	string,
	pointer,
	decimal,
	integer,
	udecimal,
	lhex,
	Hhex
}	t_conversion;

typedef bool	t_flags[FLAGS_N];

typedef struct s_options
{
	long			padding;
	char			padd_char;
	t_conversion	conv;
	t_flags			flags;
}	t_options;

int		charset_index(char c, char *charset);

void	*free_fail(void *to_free);

t_options	*parse_format(char *fmt_start);

#endif
