# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joaooliv <joaooliv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/09 17:03:21 by joaooliv          #+#    #+#              #
#    Updated: 2022/09/15 15:18:38 by joaooliv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFILES	= $(shell find ./src -type f -name "*.c") printf.c printf_tester.c
OBJS	= ${CFILES:.c=.o}

CC 	= gcc
CFLAGS 	= -I .
NAME 	= test

# all:		$(NAME)

$(NAME) :	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:		fclean $(NAME)
