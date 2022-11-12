/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaooliv <joaooliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 15:07:04 by joaooliv          #+#    #+#             */
/*   Updated: 2022/11/02 16:45:21 by joaooliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

size_t	str_len(char *s1);
char	*read_line_free(char *prefix, char *str, char **cont, int *found_nl);
void	reset_buffer(t_buffer **prev_buffer);
void	*cleanup(t_buffer *buffers[], int fd, char *line);
int		read_to_buf(t_buffer *c_b, int fd, size_t n);

// reads a line
char	*get_next_line(int fd)
{
	char			*line;
	static t_buffer	*buf[200];
	int				nl;
	t_buffer		*c_b;

	if (fd > FOPEN_MAX || fd < 0)
		return (0);
	if (!buf[fd])
		reset_buffer(&buf[fd]);
	c_b = buf[fd];
	nl = 0;
	line = 0;
	while (!nl && c_b->bytes_last_read)
	{
		if (!c_b->it || c_b->it - c_b->buf >= (long int) c_b->bytes_last_read)
		{
			if (!read_to_buf(c_b, fd, BUFFER_SIZE))
				return (cleanup(buf, fd, line));
		}
		else
			line = read_line_free(line, c_b->it, &(c_b->it), &nl);
	}
	if (c_b->bytes_last_read == 0)
		cleanup(buf, fd, 0);
	return (line);
}
