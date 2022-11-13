	# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joaooliv <joaooliv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/04 12:18:00 by joaooliv          #+#    #+#              #
#    Updated: 2022/11/09 10:41:42 by joaooliv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# sources

INCLUDES	= .

CFILES		= ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c 	ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c ft_charset_index.c ft_free_fail.c

BONUS_CFILES	= ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c

# config

CC 		= gcc
CFLAGS		= -Wall -Wextra -Werror -I $(INCLUDES)
AR		= ar rcvs
RM		= rm -rfv

NAME		= libft.a

DEF_COLOR	= \033[0;39m
GRAY		= \033[0;90m
RED		= \033[0;91m
GREEN		= \033[0;92m
YELLOW		= \033[0;93m
BLUE		= \033[0;94m
MAGENTA		= \033[0;95m
CYAN		= \033[0;96m
WHITE		= \033[0;97m

OBJS		= ${CFILES:.c=.o}
BONUSOBJS	= $(BONUS_CFILES:.c=.o)

# recipies

all: 		$(NAME) 

$(NAME):	$(OBJS)
			@printf "\n$(WHITE)%-50.50s$(DEF_COLOR)\n" "Making $(NAME)"
			@$(AR) $(NAME) $(OBJS)
			@echo "$(GREEN)Done.$(DEF_COLOR)"

bonus:		$(BONUSOBJS) $(NAME)
			@echo -n "$(WHITE)"
			@$(AR) $(NAME) $(BONUSOBJS)
			@echo -n "$(DEF_COLOR)"

%.o: 		%.c
			@printf "$(GRAY)Compiling $(CYAN)%-40.40s$(GRAY)...$(DEF_COLOR)" $<
			@$(CC) $(CFLAGS) -c -o $@ $<
			@printf "\r$(GREEN)Compiled %-44.44s$(DEF_COLOR)\n" $<

clean:
			@echo -n "$(RED)"
			@rm -vf $(OBJS) $(BONUSOBJS)
			@echo -n "$(DEF_COLOR)"

fclean:		clean
			@echo -n "$(RED)"
			@rm -vf $(NAME)
			@echo -n "$(DEF_COLOR)"

# so:
#	$(CC) -nostartfiles -fPIC $(CFLAGS) $(CFILES) $(BONUS_CFILES)
#	gcc -nostartfiles -shared -o libft.so $(OBJS) $(BONUSOBJS)

re:		fclean $(NAME)
