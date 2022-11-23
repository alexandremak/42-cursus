# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amak <amak@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/16 22:05:58 by amak              #+#    #+#              #
#    Updated: 2022/11/20 03:02:12 by amak             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SOURCES = ft_isalpha ft_isdigit ft_isalnum ft_isascii ft_isprint \
			ft_strlen ft_memset ft_bzero ft_memcpy ft_memmove \
			ft_strlcpy ft_strlcat ft_toupper ft_tolower ft_strchr \
			ft_strrchr ft_strncmp ft_memchr ft_memcmp ft_strnstr \
			ft_atoi ft_calloc ft_strdup ft_substr ft_strjoin \
			ft_strtrim ft_split ft_itoa ft_strmapi ft_striteri \
			ft_putchar_fd ft_putstr_fd ft_putendl_fd ft_putnbr_fd

OBJECTS = $(SOURCES:=.o)

B_SOURCES = ft_lstnew ft_lstadd_front ft_lstsize ft_lstlast \
			ft_lstadd_back ft_lstdelone ft_lstclear ft_lstiter \
			ft_lstmap

B_OBJECTS = $(B_SOURCES:=.o)

all: $(NAME)
	
$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

bonus: $(B_OBJECTS)
	ar rcs $(NAME) $(B_OBJECTS)

clean:
	rm -f $(OBJECTS) $(B_OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
