# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joaooliv <joaooliv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/09 17:04:43 by joaooliv          #+#    #+#              #
#    Updated: 2022/09/22 23:11:28 by joaooliv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# config

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -I .
RM			= rm -rfv

NAME		= ./test

DEF_COLOR	= \033[0;39m
GRAY		= \033[0;90m
RED			= \033[0;91m
GREEN		= \033[0;92m
YELLOW		= \033[0;93m
BLUE		= \033[0;94m
MAGENTA		= \033[0;95m
CYAN		= \033[0;96m
WHITE		= \033[0;97m

# sources

CFILES		= get_next_line_utils.c get_next_line.c main.c
OBJS		= ${CFILES:.c=.o}

# recipies

all:		$(NAME)

$(NAME):	$(OBJS)
		@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
		@printf "$(GREEN)Compiled executable -> %-30.30s$(DEF_COLOR)\n" $(NAME)

%.o: 		%.c
		@printf "$(GRAY)Compiling $(CYAN)%-40.40s$(GRAY)...$(DEF_COLOR)" $<
		@$(CC) $(CFLAGS) -c -o $@ $<
		@printf "\r$(GREEN)Compiled %-44.44s$(DEF_COLOR)\n" $<

clean:
		@echo -n "$(RED)"
		@$(RM) $(OBJS)
		@echo -n "$(DEF_COLOR)"

fclean: 	clean
		@echo -n "$(RED)"
		@$(RM) $(NAME)
		@echo -n "$(DEF_COLOR)"

re:			fclean $(NAME)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
