/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaooliv <joaooliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:51:40 by joaooliv          #+#    #+#             */
/*   Updated: 2022/09/22 23:03:33 by joaooliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// a very complicated function and hard to understand
// has guards for null string
size_t	str_len(char *s1)
{
	size_t	counter;

	counter = 0;
	while (s1 && s1[counter])
		counter++;
	return (counter);
}

// reads a line from str or until it reaches the end of str
// cont will point to the next position on str
// found_nl will be set to 1 if it found a nl
// prefixes the line read with the given prefix
// frees both prefix and str
// TODO change to receive t_buffer as arg
char	*read_line_free(char *prefix, char *str, char **cont, int *found_nl)
{
	char	*new_line;
	char	*new_line_it;
	char	*it;

	it = str;
	while (str && *it && (it == str || *(it - 1) != '\n'))
		it++;
	new_line = (char *) malloc(sizeof(char) * (str_len(prefix) + it - str + 1));
	new_line_it = new_line;
	if (!new_line || it - str == 0)
		return (0);
	it = prefix;
	while (prefix && *it)
		*new_line_it++ = *it++;
	it = str;
	while (str && *it && (it == str || *(it - 1) != '\n'))
		*new_line_it++ = *it++;
	if (found_nl && str && it != str && *(it - 1) == '\n')
		*found_nl = 1;
	*new_line_it = 0;
	if (cont)
		*cont = it;
	free(prefix);
	return (new_line);
}

// resets a file buffer
void	reset_buffer(t_buffer **prev_buffer)
{
	t_buffer	*buffer;

	buffer = (t_buffer *) malloc(sizeof(t_buffer));
	if (!buffer)
		return ;
	buffer->buf = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer->buf)
	{
		buffer->it = 0;
		buffer->bytes_last_read = -1;
		if (prev_buffer)
		{
			if (*prev_buffer)
				free((*prev_buffer)->buf);
			free(*prev_buffer);
			*prev_buffer = buffer;
		}
	}
	else
	{
		free(buffer);
		buffer = 0;
	}
}

void	*cleanup(t_buffer *buffers[], int fd, char *line)
{
	if (buffers)
	{
		free(buffers[fd]->buf);
		free(buffers[fd]);
		buffers[fd] = 0;
	}
	if (line)
		free(line);
	return (0);
}

int	read_to_buf(t_buffer *c_b, int fd, size_t n)
{
	c_b->bytes_last_read = read(fd, c_b->buf, n);
	if (c_b->bytes_last_read < 0)
		return (0);
	c_b->buf[c_b->bytes_last_read] = 0;
	c_b->it = c_b->buf;
	return (1);
}
