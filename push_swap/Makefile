# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amak <amak@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/01 17:44:56 by amak              #+#    #+#              #
#    Updated: 2023/05/21 15:46:22 by amak             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc -g

CFLAGS = -Wall -Wextra -Werror

SOURCES = 	main.c \
			ft_atoi.c \
			ft_calloc.c \
			ft_lstadd_back.c \
			ft_lstadd_front.c \
			ft_lstlast.c \
			ft_lstnew.c \
			ft_lstsize.c \
			ft_split.c \
			ft_strlcpy.c \
			ft_strlen.c \
			move_operations.c \
			sort_big.c \
			sort_small.c \
			sort_utils.c \
			utilities.c

OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)
	
$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)
	
clean:
	@rm -f $(OBJECTS)
	@echo Deleted object files!

fclean: clean
	@rm -f $(NAME)
	@echo Deleted executable!

re: fclean all

.PHONY: all bonus clean fclean re
