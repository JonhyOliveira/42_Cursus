# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joaooliv <joaooliv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/09 17:03:21 by joaooliv          #+#    #+#              #
#    Updated: 2022/09/22 22:09:50 by joaooliv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# config

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -I ./includes
AR			= ar rcsv
RM			= rm -rfv

NAME 		= libftprintf.a
LIBFT		= libft
TEST_FILE	= test_file

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

CFILES		=  $(shell find ./src -type f -name "*.c") ./ft_printf.c  

OBJS		= ${CFILES:.c=.o}

# recepies

all:		$(NAME)

$(NAME) :	$(LIBFT).a $(OBJS)
		@cp $(LIBFT).a $(NAME)
		@printf "\n$(WHITE)%-50.50s$(DEF_COLOR)" "Making $(NAME)"
		@$(AR) $(NAME) $(OBJS)
		@echo "$(GREEN)done.$(DEF_COLOR)"

$(LIBFT).a:
		@make -sC $(LIBFT) # compile libft
		@cp libft/libft.a .

#$(OBJS):	$(CFILES)
#		$(eval F = $@)
#		@printf "$(YELLOW)%-50.50s$(DEF_COLOR)" "Making $F"
#		@$(CC) $(CFLAGS) -c $< -o $F
#		@echo "$(GREEN)done.$(DEF_COLOR)"

clean:
		@echo -n "$(RED)"
		@$(RM)	$(OBJS) $(LIBFT).a $(TEST_FILE).o test a.out
		@echo -n "$(DEF_COLOR)"

fclean: 	clean
		@echo -n "$(RED)"
		@$(RM) $(NAME)
		@echo -n "$(DEF_COLOR)"

test:		$(NAME) $(TEST_FILE).o
		@$(CC) -o test $(TEST_FILE).o $(NAME)  

$(TEST_FILE).o: $(TEST_FILE).c
		$(CC) -I includes -c $(TEST_FILE).c -o $(TEST_FILE).o

re:			fclean $(NAME)
