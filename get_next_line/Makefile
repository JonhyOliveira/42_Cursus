# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joaooliv <joaooliv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/09 17:04:43 by joaooliv          #+#    #+#              #
#    Updated: 2022/09/19 17:06:30 by joaooliv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFILES	= get_next_line_utils.c get_next_line.c main.c
OBJS	= ${CFILES:.c=.o}

CC 	= gcc
CFLAGS 	= -Wall -Wextra -Werror -I .
NAME 	= test

all:		$(NAME)

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean:		clean
	rm -f $(NAME)

re:			fclean $(NAME)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
