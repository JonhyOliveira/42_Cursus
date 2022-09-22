/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaooliv <joaooliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 13:47:02 by joaooliv          #+#    #+#             */
/*   Updated: 2022/09/22 22:02:44 by joaooliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internals.h"

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
	return (res);
}

void	sanitize_options(t_f_options *opts)
{
	if (opts->flags[zero] && opts->conv >= decimal && opts->conv <= Hhex)
		if (opts->precision > 0)
			opts->flags[zero] = false;
	if (opts->flags[zero] && opts->flags[minus])
		opts->flags[zero] = false;
	if (opts->flags[plus] && opts->flags[space])
		opts->flags[space] = false;
	if (opts->flags[zero])
		opts->padd_char = '0';
}

// joins two strings and frees them
char	*join_free(char *s1, char *s2)
{
	char	*joined;
	char	*j_it;
	char	*aux;

	joined = (char *) malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!joined)
			return (joined);
	j_it = joined;
	aux = s1;
	while (s1 && *s1)
			*j_it++ = *s1++;
	if (aux)
		free(aux);
	aux = s2;
	while (s2 && *s2)
			*j_it++ = *s2++;
	if (aux)
		free(aux);
	*j_it = 0;
	return (joined);
}

// char to string
char	*ctos(char c)
{
	char	*str;

	str = (char *) malloc(sizeof(char) * 2);
	str[0] = c;
	str[1] = 0;
	return (str);
}

// size of a number in a given radix
size_t	nbr_size(long long n, size_t radix)
{
	if (radix <= 1)
		return (0);
	if (n < 0)
		return (1 + nbr_size(-n, radix));
	else
		if (n >= (long long) radix)
			return (1 + nbr_size(n / radix, radix));
		else
			return (1);
}
