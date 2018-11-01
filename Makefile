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
		srcs/error_invalid_input.c \
		srcs/ft_ptrtab_free.c \
		srcs/ft_strsplit_by_substring.c \
		srcs/ft_strtab_free.c \
		srcs/ft_strtab_len.c

OBJ =	main.o \
		parse_input.o \
		valid_tetriminos.o \
		error_invalid_input.o \
		ft_ptrtab_free.o \
		ft_strsplit_by_substring.o \
		ft_strtab_free.o \
		ft_strtab_len.o

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
