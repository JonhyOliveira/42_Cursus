# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joaooliv <joaooliv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/09 17:03:21 by joaooliv          #+#    #+#              #
#    Updated: 2022/11/09 10:45:10 by joaooliv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# config

CSRC		= ./src
HEADERS		= ./includes

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -I $(HEADERS)
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

CFILES		= $(CSRC)/ft_printf.c $(CSRC)/parsing.c $(CSRC)/to_hex.c $(CSRC)/to_nbr.c $(CSRC)/to_others.c $(CSRC)/utils.c
OBJS		= ${CFILES:.c=.o}

# recipies

all:		$(NAME)

$(NAME):	$(LIBFT).a $(OBJS)
		@cp $(LIBFT).a $(NAME)
		@printf "\n$(WHITE)%-50.50s$(DEF_COLOR)\n" "Making $(NAME)"
		@$(AR) $(NAME) $(OBJS)
		@echo "$(GREEN)Done.$(DEF_COLOR)"

%.o: 		%.c
		@printf "$(GRAY)Compiling $(CYAN)%-40.40s$(GRAY)...$(DEF_COLOR)" $<
		@$(CC) $(CFLAGS) -c -o $@ $<
		@printf "\r$(GREEN)Compiled %-44.44s$(DEF_COLOR)\n" $<

$(LIBFT).a:
		@make -C $(LIBFT) bonus # compile libft
		@cp $(LIBFT)/libft.a .
		@cp $(LIBFT)/libft.h includes/libft.h

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
