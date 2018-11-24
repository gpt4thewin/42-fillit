# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/17 17:47:32 by juazouz           #+#    #+#              #
#    Updated: 2018/11/24 17:15:59 by juazouz          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I $(IDIR) -I $(LIBFT)/includes -g

IDIR = .
SDIR = .
ODIR = obj
LIBFT = libft

NAME = fillit

DEPS = $(IDIR)/fillit.h

OBJ = $(patsubst %.c,$(ODIR)/%.o,$(_SRC)) \
		$(LIBFT)/libft.a

SRC = $(patsubst %,$(SDIR)/%,$(_SRC)))

_SRC =	create_grid.c \
		debug_print_tetriminos.c \
		free_grid.c \
		input_parse.c \
		main.c \
		print_grid.c \
		solve.c \
		solve_core.c \
		tetriminos_normalize.c \
		tetriminos_validate.c \
		utils.c

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
