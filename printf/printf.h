/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaooliv <joaooliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:17:08 by joaooliv          #+#    #+#             */
/*   Updated: 2022/09/15 15:10:15 by joaooliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

#define PRINTF_FLAGS "#+-0 "
#define FLAGS_N 5

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

int		ft_printf(const char *fmt, ...);

char	*prefix_str(char *prefix, char *str);

char	*suffix_str(char *suffix, char *str);

size_t	str_len(char *str);

#endif
