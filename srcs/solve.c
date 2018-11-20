/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 17:49:23 by juazouz           #+#    #+#             */
/*   Updated: 2018/11/20 11:29:20 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fillit.h"

static int		can_place(t_grid *grid, t_tetriminos *tetriminos, int x, int y)
{
	int				i;
	t_point			point;

	i = 0;
	while (i < TETRIMINOS_SIZE)
	{
		point = tetriminos->points[i];
		if (!IN_BOUNDS(grid, point.x + x, point.y + y) ||
			CELL_AT(grid, point.x + x, point.y + y) != NULL)
			return (0);
		i++;
	}
	return (1);
}

static void		do_place(t_grid *grid, t_tetriminos *tetriminos, int x, int y)
{
	int				i;
	t_point			point;

	i = 0;
	while (i < TETRIMINOS_SIZE)
	{
		point = tetriminos->points[i];
		CELL_AT(grid, point.x + x, point.y + y) = tetriminos;
		i++;
	}
}

static void		remove_at(t_grid *grid, t_tetriminos *tetriminos, int x, int y)
{
	int				i;
	t_point			point;

	i = 0;
	while (i < TETRIMINOS_SIZE)
	{
		point = tetriminos->points[i];
		CELL_AT(grid, point.x + x, point.y + y) = NULL;
		i++;
	}
}

int				find_space(t_grid *grid, t_tetriminos *tetriminos, int *x, int *y)
{
	while (1)
	{
		if (can_place(grid, tetriminos, *x, *y))
		{
			return (1);
		}
		(*x)++;
		if (*x >= grid->size)
		{
			(*x) = 0;
			(*y)++;
		}
		if (!IN_BOUNDS(grid, *x, *y))
		{
			return (0);
		}
	}
	return (0);
}

int				solve_core(t_grid *grid, t_tetriminos *tetriminos, int count, int index)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (find_space(grid, &tetriminos[index], &x, &y))
	{
		do_place(grid, &tetriminos[index], x, y);
		// debug
		print_grid(grid);
		// getchar();

		if (index == count - 1 ||
			solve_core(grid, tetriminos, count, index + 1))
			return (1);
		remove_at(grid, &tetriminos[index], x, y);
		x++;
	}
	return (0);
}

static t_grid	*solve_with_grid_size(t_tetriminos *tetriminos, int count, int grid_size)
{
	t_grid	*grid;

	grid = create_grid(grid_size);
	if (solve_core(grid, tetriminos, count, 0))
		return (grid);
	free_grid(grid);
	return (NULL);
}

t_grid			*solve(t_tetriminos *tetriminos, int count)
{
	int		i;
	t_grid	*result;

	i = 1;
	while (i < GRID_SIZE_LIMIT)
	{
		result = solve_with_grid_size(tetriminos, count, i);
		if (result != NULL)
			return (result);
		i++;
	}
	return (NULL);
}
