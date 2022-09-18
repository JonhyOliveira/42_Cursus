/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaooliv <joaooliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:17:08 by joaooliv          #+#    #+#             */
/*   Updated: 2022/09/18 19:47:53 by joaooliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

// BIG BOY
int		ft_printf(const char *fmt, ...);

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

// parses the format starting at fmt_start and returns
// the format 
t_f_options	*parse_format(char *fmt_start, char **cont_fmt);

char	*prefix_str(char *prefix, char *str);

char	*suffix_str(char *suffix, char *str);

size_t	str_len(char *str);

// character to string
char	*ctos(char c);

// does general option sanitization
void	sanitize_options(t_f_options *opts);

// joins two strings and frees them
char	*join_free(char **s1_ptr, char *s2);

#endif
