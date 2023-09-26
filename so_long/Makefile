# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amak <amak@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/13 20:47:10 by amak              #+#    #+#              #
#    Updated: 2023/09/26 20:57:42 by amak             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc -g

CFLAGS = -Wall -Wextra -Werror

LFLAGS = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

SOURCES = 	main.c \
			ft_strchr.c \
			ft_strdup.c \
			ft_strlen.c \
			get_next_line.c \
			get_next_line_utils.c \
			validate_file.c \
			validate_aux.c \
			validate_map.c \
			validate_path.c \
			mlx_window.c \
			map_builder.c \
			moving.c
			
OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
#	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)
	$(CC) $(CFLAGS) $(OBJECTS) $(LFLAGS) -o $(NAME)
	
clean:
	@rm -f $(OBJECTS)
	@echo Deleted object files!

fclean: clean
	@rm -f $(NAME)
	@echo Deleted executable!

re: fclean all

.PHONY: all bonus clean fclean re
