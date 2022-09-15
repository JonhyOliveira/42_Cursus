/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_formatted.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaooliv <joaooliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 13:47:02 by joaooliv          #+#    #+#             */
/*   Updated: 2022/09/15 16:14:42 by joaooliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "formats.h"

// size of a number in a given radix
size_t	nbr_size(long long n, size_t radix)
{
	if (radix <= 1)
		return (0);
	if (n < 0)
		return (1 + nbr_size(-n, radix));
	else
		if (n >= radix)
			return (1 + nbr_size(n / radix, radix));
		else
			return (1);
}

// joins two strings and frees them
char	*join_free(char **s1_ptr, char *s2)
{
	char	*joined;
	char	*j_it;
	char	*s1_it;
	char	*s2_it;

	joined = (char *) malloc(sizeof(char) * (str_len(*s1_ptr) + str_len(s2) + 1));
	if (!joined)
			return (joined);
	j_it = joined;
	s1_it = *s1_ptr;
	s2_it = s2;
	while (s1_it && *s1_it)
			*j_it++ = *s1_it++;
	while (s2_it && *s2_it)
			*j_it++ = *s2_it++;
	*j_it = 0;
	if (s1_ptr)
	{
		free(*s1_ptr);
		*s1_ptr = joined;
	}
	free(s2);
//	printf("joined: '%s' ", joined);
	return (joined);
}

static char	*to_numeric(int n, t_f_options *opts)
{
	if (opts->conv >= lhex && opts->conv <= Hhex)
		return (to_hex(n, opts));
	else if (opts->conv >= decimal && opts->conv <= udecimal)
		return (to_dec(n, opts));
	else
		return (0);
}

static void	do_padding(char **str_ptr, t_f_options *opts)
{
	char	*padded;
	char	*padded_it;
	char	*str_it;
	long	padding_left;

	padding_left = opts->field_width - str_len(*str_ptr);
	if (padding_left > 0)
	{
		padded = (char *) malloc(sizeof(char) * (opts->field_width + 1));
		if (!padded)
			return ;
		padded_it = padded;
		while (padding_left-- > 0)
			*padded_it++ = opts->padd_char;
		str_it = *str_ptr;
		while (str_it && *str_it)
			*padded_it++ = *str_it++;
		*padded_it = 0;
		if (*str_ptr)
		{
			free(*str_ptr);
			*str_ptr = padded;
		}
	}
}

void	join_formatted(t_f_options *opts, va_list args, char **dest, size_t index)
{
	va_list	copy;
	char	*res;	

	va_copy(copy, args);
	while (index-- > 1)
		va_arg(copy, void *);
	if (opts->conv >= character && opts->conv <= string)
		res = to_character(va_arg(copy, void *), opts);
	else if (opts->conv == pointer)
		res = to_pointer(va_arg(copy, void *), opts);
	else if (opts->conv >= decimal && opts->conv < udecimal)
		res = to_numeric(va_arg(copy, int), opts);
	else if (opts->conv >= udecimal && opts->conv < Hhex)
		res = to_numeric(va_arg(copy, unsigned int), opts);
	do_padding(&res, opts);
	join_free(dest, res);
}
