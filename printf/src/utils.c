/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaooliv <joaooliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 13:47:02 by joaooliv          #+#    #+#             */
/*   Updated: 2022/09/19 18:50:26 by joaooliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internals.h"

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
