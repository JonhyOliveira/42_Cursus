/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaooliv <joaooliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 15:07:04 by joaooliv          #+#    #+#             */
/*   Updated: 2022/09/07 20:18:26 by joaooliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

// a very complicated function and hard to understand
// has guards for null string
static size_t	ft_strle(char *s1)
{
	size_t	counter;

	counter = 0;
	while (s1 && s1[counter])
		counter++;
	return (counter);
}

// joins and frees two strings
// has guards for null strings
static char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*join;
	char	*join_it;
	size_t	index;

	join = (char *) malloc(sizeof(char) * (ft_strle(s1) + ft_strle(s2) + 1));
	if (join)
	{
		join_it = join;
		index = 0;
		while (s1 && s1[index])
			*join_it++ = s1[index++];
		index = 0;
		while (s2 && s2[index])
			*join_it++ = s2[index++];
		*join_it = 0;
	}
	free(s1);
	free(s2);
	return (join);
}

// reads a line from str or until it reaches the end of str
// cont will point to the next position on str
// found_nl will be set to 1 if it found a nl
static char	*read_line(char *str, char **cont, int *found_nl)
{
	char	*line;
	size_t	index;

	index = 0;
	while (str[index] && str[index] != '\n')
		index++;
	line = (char *) malloc(sizeof(char) * (index + 1));
	if (!line)
		return (0);
	index = -1;
	while (str[++index] && str[index] != '\n')
		line[index] = str[index];
	line[index] = 0;
	if (found_nl && str[index] == '\n')
		*found_nl = 1;
	if (cont)
		*cont = str + index + 1;
	return (line);
}

// resets a file buffer
static void	reset_buffer(t_buffer **prev_buffer)
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

// reads a 
char	*get_next_line(int fd)
{
	char			*line;
	static t_buffer	*buf[200];
	int				nl;
	t_buffer		*c_b;

	if (!buf[fd] || !buf[fd]->bytes_last_read)
		reset_buffer(&buf[fd]);
	if (!buf[fd])
		return (0);
	line = 0;
	c_b = buf[fd];
	nl = 0;
	while (!nl && c_b->bytes_last_read)
	{
		if (!c_b->it || c_b->it - c_b->buf >= (long int) c_b->bytes_last_read)
		{	
			c_b->bytes_last_read = read(fd, c_b->buf, BUFFER_SIZE);
			c_b->buf[c_b->bytes_last_read] = 0;
			c_b->it = c_b->buf;
		}
		else
			line = ft_strjoin_free(line, read_line(c_b->it, &(c_b->it), &nl));
	}
	return (line);
}
