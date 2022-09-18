# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joaooliv <joaooliv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/09 17:03:21 by joaooliv          #+#    #+#              #
#    Updated: 2022/09/18 20:08:40 by joaooliv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFILES	= $(shell find ./formats -type f -name "*.c") printf.c printf_tester.c $(shell find . -type f -name "*_utils.c")
OBJS	= ${CFILES:.c=.o}

CC 	= gcc
CFLAGS 	= -Wall -Wextra -Werror -I .
NAME 	= test

# all:		$(NAME)

$(NAME) :	$(OBJS)
	make libft
	$(CC) $(CFLAGS) libft/libft.a  $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:		fclean $(NAME)
