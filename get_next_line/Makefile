# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joaooliv <joaooliv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/09 17:04:43 by joaooliv          #+#    #+#              #
#    Updated: 2022/09/09 17:04:44 by joaooliv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFILES	= get_next_line_utils.c get_next_line.c main.c
OBJS	= ${CFILES:.c=.o}

CC 	= gcc
CFLAGS 	= -Wall -Wextra -Werror -I .
NAME 	= test

all:		$(NAME)

$(NAME) :	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) libft.a  -o $(NAME)

clean:
	rm -f $(OBJS)

re:		$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) libft.a  -o $(NAME)
