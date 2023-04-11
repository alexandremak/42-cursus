# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amak <amak@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/17 00:41:51 by amak              #+#    #+#              #
#    Updated: 2023/04/03 21:37:58 by amak             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = cc -g

CFLAGS = -Wall -Wextra -Werror

SOURCES = 	pipex.c pipex_utils.c processes.c ft_calloc.c ft_memcpy.c \
			ft_split.c ft_strdup.c ft_strjoin.c ft_strlcpy.c ft_strlen.c \
			ft_strncmp.c ft_substr.c 

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
