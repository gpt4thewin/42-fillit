# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/17 17:47:32 by juazouz           #+#    #+#              #
#    Updated: 2018/11/28 15:25:46 by juazouz          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I $(IDIR) -I $(LIBFT)/includes

IDIR = .
SDIR = .
ODIR = obj
LIBFT = libft

NAME = fillit

DEPS = $(IDIR)/fillit.h

OBJ = $(patsubst %.c,$(ODIR)/%.o,$(_SRC))

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
		utils.c \
		ft_abs.c \
		ft_safemalloc.c

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	gcc $^ $(LIBFT)/libft.a -o $@

$(ODIR)/%.o: $(SDIR)/%.c $(DEPS)
	@mkdir -p $(dir $@)
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
