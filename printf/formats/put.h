/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaooliv <joaooliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:14:25 by joaooliv          #+#    #+#             */
/*   Updated: 2022/09/08 18:47:46 by joaooliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUT_H
# define PUT_H

#include "../printf.h"
#include <unistd.h>

void	put_char(char c, t_options opts);
void	put_str(char *s, t_flags flags, t_options opts);
void	put_pointer(void *p, t_flags flags);
void	put_nbr(long number, t_flags flags, bool is_signed);

#endif
