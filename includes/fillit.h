/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 19:05:02 by marvin            #+#    #+#             */
/*   Updated: 2018/11/19 12:43:00 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
*	Includes.
*/

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "libft.h"

/*
*	Defines.
*/

// debug shit
#define DEBUG_LINE printf("%s@%d\n", __FILE__, __LINE__);
#define DEBUG_PTR(ptr) printf("%p\n", ptr);
#define DEBUG_INT(n) printf("%d\n", n);

#define BUFFER_SIZE 4096
#define TETRIMINOS_SIZE 4
#define INPUT_LINE_LEN 4
#define INPUT_LINE_COUNT TETRIMINOS_SIZE
#define INPUT_TETRIMINOS_SIZE (TETRIMINOS_SIZE * (INPUT_LINE_LEN + 1))

#define TILE_AT(grid, x, y) grid->tiles[x + grid->width * y]
#define TILES_COUNT(grid) (grid->height * grid->width)

/*
*	Types.
*/

typedef struct s_tetriminos t_tetriminos;
typedef struct s_point t_point;
typedef struct s_grid t_grid;

struct s_point
{
	int		x;
	int		y;
};

struct s_tetriminos
{
	int		height;
	int		width;
	int		points_count;
	t_point	points[TETRIMINOS_SIZE];
};

struct s_grid
{
	int				height;
	int				width;
	t_tetriminos	*tiles;
};

/*
*	Fillit functions.
*/

int				input_parse(char *input, t_tetriminos *tetriminos, int count);
int				tetriminos_validate(t_tetriminos *tetriminos);
void			tetriminos_normalize(t_tetriminos *tetriminos);
void			error_invalid_input();

void			debug_print_tetriminos(t_tetriminos *tetriminos);
