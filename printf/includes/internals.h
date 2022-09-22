/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internals.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaooliv <joaooliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:14:25 by joaooliv          #+#    #+#             */
/*   Updated: 2022/09/22 11:26:07 by joaooliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_FORMATS_H
# define PRINTF_FORMATS_H

#include "printf.h"
#include "../libft/libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdbool.h>

#define PRINTF_FLAGS "#+-0 "
#define FLAGS_N 5

// ordinal representation of the flags as they come up in the flags string
typedef enum	e_flag
{
	hash,
	plus,
	minus,
	zero,
	space,
}	t_flag;

#define PRINTF_CONVERSIONS "cspdiuxX"
#define CONVERSIONS_N 8

// ordinal representation of the convs as they come up in the convs string
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

// t_flags is an array of booleans indicating if each flag is up or not
typedef bool	t_flags[FLAGS_N];

typedef struct s_f_options
{
	long			field_width;
	long			precision;
	long			arg_i;
	char			padd_char;
	t_conversion	conv;
	t_flags			flags;
}	t_f_options;

// returns the index of c in charset, or -1 if not found
long	charset_index(char c, char *charset);

// frees to_free and returns a NULL pointer
void	*free_fail(void *to_free);

// character to string
char	*ctos(char c);

// joins two strings and frees them
char	*join_free(char *s1, char *s2);

void	sanitize_options(t_f_options *opts);

t_f_options	*dup_options(t_f_options *opts);

// parses the format starting at fmt_start and returns
// the format 
t_f_options	*parse_format(char *fmt_start, char **cont_fmt);

// Converter functions
//     These functions convert the next argument in the argument list to a string 
//   in a specific format, based on the format options (f_options).
char	*to_character(t_f_options *opts, va_list args);
char	*to_str(t_f_options *opts, va_list args);
char	*to_hex(t_f_options *opts, va_list args);
char	*to_dec(t_f_options *opts, va_list args);
char	*to_pointer(t_f_options *opts, va_list args);

// size of a number in a given radix
size_t	nbr_size(long long n, size_t radix);

#endif
