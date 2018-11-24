/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 19:05:02 by marvin            #+#    #+#             */
/*   Updated: 2018/11/24 18:19:39 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

/*
**	Includes.
*/

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "libft.h"

/*
**	Defines.
*/

# define BUFFER_SIZE 4096
# define TETRIMINOS_SIZE 4
# define INPUT_LINE_LEN 4
# define INPUT_LINE_COUNT TETRIMINOS_SIZE
# define INPUT_TETRIMINOS_SIZE (TETRIMINOS_SIZE * (INPUT_LINE_LEN + 1))
# define GRID_SIZE_LIMIT 8

/*
**	Types.
*/

typedef struct s_tetriminos	t_tetriminos;
typedef struct s_point		t_point;
typedef struct s_grid		t_grid;

struct						s_point
{
	int		x;
	int		y;
};

struct						s_tetriminos
{
	int		id;
	int		height;
	int		width;
	int		points_count;
	t_point	points[TETRIMINOS_SIZE];
};

struct						s_grid
{
	int				size;
	t_tetriminos	**cells;
};

/*
**	Fillit functions.
*/

int							input_parse(char *input,
										t_tetriminos *tetri,
										int count);
int							tetriminos_validate(t_tetriminos *tetri);
void						tetriminos_normalize(t_tetriminos *tetri);
void						error_invalid_input();

void						debug_print_tetriminos(t_tetriminos *tetri);

t_grid						*solve(t_tetriminos *tetri, int count);
int							solve_core(t_grid *grid,
										t_tetriminos *tetri,
										int count,
										int index);

t_grid						*create_grid(int size);
void						free_grid(t_grid *grid);

void						print_grid(t_grid *grid);
int							in_bounds(t_grid *grid, int x, int y);
t_tetriminos				*cell_at(t_grid *grid, int x, int y);
void						set_cell_at(t_grid *grid, int x, int y,
										t_tetriminos *val);
int							cells_count(t_grid *grid);
int							distance(t_point *a, t_point *b);

int							ft_abs(int n);

#endif
