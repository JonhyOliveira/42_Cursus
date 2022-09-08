/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaooliv <joaooliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:13:59 by joaooliv          #+#    #+#             */
/*   Updated: 2022/09/08 16:42:43 by joaooliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "put.h"

void	put_char(char c, t_options opts)
{
	int		index;

	index = opts.padding_left;
	if (index <= 0)
		index = 0;
	while (--index > 0)
		write(1, &opts.padd_char, 1);
	write(1, &c, 1);
	index = -1;
	while (++index < opts.padding_right)
		write(1, &opts.padd_char, 1);
}
