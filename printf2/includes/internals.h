/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internals.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaooliv <joaooliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:14:25 by joaooliv          #+#    #+#             */
/*   Updated: 2022/11/09 12:20:59 by joaooliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERNALS_H
# define INTERNALS_H

# include "printf.h"
# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdbool.h>

# define PRINTF_FLAGS "#+-0 "
# define FLAGS_N 5

// ordinal representation of the flags as they come up in the flags string
typedef enum e_flag
{
	hash,
	plus,
	minus,
	zero,
	space,
}	t_flag;

# define PRINTF_CONVERSIONS "\%cspdiuxX"
# define CONVERSIONS_N 9

// ordinal representation of the convs as they come up in the convs string
typedef enum e_conversion
{
	null,
	character,
	string,
	pointer,
	decimal,
	integer,
	udecimal,
	lhex,
	Hhex
}	t_conversion;

typedef struct s_f_options
{
	long			field_width;
	long			precision;
	long			arg_i;
	char			padd_char;
	t_conversion	conv;
	bool			flags[FLAGS_N];
}	t_f_options;

// character to string
char		*ctos(char c);

// joins two strings and frees them
char		*join_free(char *s1, char *s2);

void		sanitize_options(t_f_options *opts);

t_f_options	*dup_options(t_f_options *opts);

// parses the format starting at fmt_start and returns
// the format 
t_f_options	*parse_format(char *fmt_start, char **cont_fmt);

// Converter functions
//     These functions convert the next argument in the argument 
//   list to a char list in a specific format, based on the format
//   options (t_f_options).
t_list		*to_character(t_f_options *opts, va_list args);
t_list		*to_str(t_f_options *opts, va_list args);
t_list		*to_hex(t_f_options *opts, va_list args);
t_list		*to_dec(t_f_options *opts, va_list args);
t_list		*to_pointer(t_f_options *opts, va_list args);
t_list		*to_perc(t_f_options *opts, va_list args);

// size of a number in a given radix
size_t		nbr_size(long long n, size_t radix);

#endif
