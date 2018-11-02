# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/17 17:47:32 by juazouz           #+#    #+#              #
#    Updated: 2018/10/17 17:47:32 by juazouz          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

FLAGS = -Wall -Wextra -Werror -gdwarf-3 -I includes

TARGET = fillit

SRC =	srcs/main.c \
		srcs/parse_input.c \
		srcs/valid_tetriminos.c \
		srcs/normalize_tetriminos.c \
		srcs/error_invalid_input.c \
		srcs/debug_print_tetriminos.c

OBJ =	main.o \
		parse_input.o \
		valid_tetriminos.o \
		normalize_tetriminos.o \
		error_invalid_input.o \
		debug_print_tetriminos.o

$(TARGET):
	# @$(CC) $(FLAGS) -c $(SRC)
	# @$(CC) $(OBJ) libft.a -o $(TARGET)
	@$(CC) $(FLAGS) $(SRC) libft.a -o $(TARGET)

all: $(TARGET)

clean:
	@rm -f $(OBJ)

fclean:	clean
	@rm -f $(TARGET)

re:	fclean all
