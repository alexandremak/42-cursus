# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amak <amak@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/24 18:48:45 by amak              #+#    #+#              #
#    Updated: 2022/11/24 23:16:19 by amak             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SOURCES = 	ft_printf.c pf_putchar.c pf_putnbrbase.c pf_putnbr_un.c pf_putstr.c \
			ft_strlen.c

OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)
	
$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
