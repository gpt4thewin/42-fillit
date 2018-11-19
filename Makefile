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

CFLAGS = -Wall -Wextra -Werror -I $(IDIR) -I $(LIBFT)/includes

IDIR = includes
SDIR = srcs
ODIR = obj
LIBFT = libft

NAME = fillit

DEPS = $(IDIR)/fillit.h \
		$(LIBFT)/includes/libft.h

OBJ = $(patsubst %.c,$(ODIR)/%.o,$(_SRC)) \
		$(LIBFT)/libft.a

SRC = $(patsubst %,$(SDIR)/%,$(_SRC)))

_SRC =	main.c \
		input_parse.c \
		tetriminos_validate.c \
		tetriminos_normalize.c \
		error_invalid_input.c \
		debug_print_tetriminos.c

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	gcc $^ -o $@

$(ODIR)/%.o: $(SDIR)/%.c $(DEPS)
	@mkdir -p $(dir $@)
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -f $(OBJ)
	make -C $(LIBFT) clean

fclean:	clean
	rm -f $(NAME)
	make -C $(LIBFT) fclean

re:	fclean all

$(LIBFT)/libft.a:
	make -C $(LIBFT) libft.a
