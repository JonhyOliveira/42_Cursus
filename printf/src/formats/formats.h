/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formats.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaooliv <joaooliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:14:25 by joaooliv          #+#    #+#             */
/*   Updated: 2022/09/15 16:15:04 by joaooliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_FORMATS_H
# define PRINTF_FORMATS_H

#include "printf.h"

// joins two strings and frees them
char	*join_free(char **s1_ptr, char *s2);

void	join_formatted(t_f_options *opts, va_list args, char **final_str_ptr, size_t index);
char	*to_character(void *mem, t_f_options *opts);
char	*to_hex(unsigned int n, t_f_options *opts);
char	*to_dec(int n, t_f_options *opts);
char	*to_pointer(void *pointer, t_f_options *opts);

size_t	nbr_size(long long n, size_t radix);

#endif
