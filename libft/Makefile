# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joaooliv <joaooliv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/04 12:18:00 by joaooliv          #+#    #+#              #
#    Updated: 2022/09/19 18:09:28 by joaooliv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFILES		=$(shell ls *.c)
OBJS		=${CFILES:.c=.o}

HEADERS_DIR	=includes/

BONUSFILES	=$(shell ls ft_lst*.c)
BONUSOBJS	=$(BONUSFILES:.c=.o)

CC 			= gcc
CFLAGS		= -Wall -Wextra -Werror -I .
NAME		= libft.a

all: 		$(NAME) 

$(NAME):	$(OBJS)
			ar rcs $(NAME) $(OBJS)

bonus:		$(BONUSOBJS)
			ar rcs $(NAME) $(BONUSOBJS)

clean:
			rm -f $(OBJS) $(BONUSOBJS)

fclean:		clean
			rm -f $(NAME)

so:			$(OBJS)
			gcc -shared -o libft.so $(OBJS)

re:		fclean $(NAME)
