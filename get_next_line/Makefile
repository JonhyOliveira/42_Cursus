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
