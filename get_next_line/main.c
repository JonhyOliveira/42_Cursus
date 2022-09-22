/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaooliv <joaooliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:25:53 by joaooliv          #+#    #+#             */
/*   Updated: 2022/09/08 08:39:31 by joaooliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

#include <stdio.h>
#include <fcntl.h>

void	put_str(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int	main(int argc, char *argv[])
{
	(void) argc;
	if (argc > 1)
	{
		int fd = open(argv[1], O_RDONLY);
		if (fd < 0)
			fd = 0;
		char	*line = 0;
		int	line_count = 0;
		do 
		{
			line = get_next_line(fd);
			if (line)
				put_str(line);
			line_count++;
		}
		while (line && line_count < 50);
	}
}
