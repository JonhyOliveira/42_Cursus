/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaooliv <joaooliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:10:49 by joaooliv          #+#    #+#             */
/*   Updated: 2022/09/22 15:51:32 by joaooliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

#define args 'A', "loha, camaradas da", 42 
#define FMT "%10c%.4s '%3$+4.12d' (unsigned %3$+.2u, hex %3$#+.2x)\n"

int	main()
{
	printf(FMT, args);
	ft_printf(FMT, args);
}
