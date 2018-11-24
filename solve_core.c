/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_core.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 11:56:50 by juazouz           #+#    #+#             */
/*   Updated: 2018/11/24 19:07:03 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		can_place(t_grid *grid, t_tetriminos *tetri, int x, int y)
{
	int				i;
	t_point			point;

	i = 0;
	while (i < TETRIMINOS_SIZE)
	{
		point = tetri->points[i];
		if (!in_bounds(grid, point.x + x, point.y + y) ||
			cell_at(grid, point.x + x, point.y + y) != NULL)
			return (0);
		i++;
	}
	return (1);
}

static void		do_place(t_grid *grid, t_tetriminos *tetri, int x, int y)
{
	int				i;
	t_point			point;

	i = 0;
	while (i < TETRIMINOS_SIZE)
	{
		point = tetri->points[i];
		set_cell_at(grid, point.x + x, point.y + y, tetri);
		i++;
	}
}

static void		remove_at(t_grid *grid, t_tetriminos *tetri, int x, int y)
{
	int				i;
	t_point			point;

	i = 0;
	while (i < TETRIMINOS_SIZE)
	{
		point = tetri->points[i];
		set_cell_at(grid, point.x + x, point.y + y, NULL);
		i++;
	}
}

static int		find_space(t_grid *grid, t_tetriminos *tetri, int *x, int *y)
{
	while (*y < grid->size && *y + tetri->height - 1 < grid->size)
	{
		while (*x < grid->size && *x + tetri->width - 1 < grid->size)
		{
			if (can_place(grid, tetri, *x, *y))
			{
				return (1);
			}
			if (!in_bounds(grid, (*x) + tetri->width - 1, (*y) + tetri->height - 1))
			{
				return (0);
			}
			(*x)++;
		}
		(*x) = 0;
		(*y)++;
	}
	return (0);
}

int				solve_core(t_grid *grid,
							t_tetriminos *tetri,
							int count,
							int index)
{
	int	x;
	int	y;

	if (index == count)
		return (1);
	x = 0;
	y = 0;
	while (find_space(grid, &tetri[index], &x, &y))
	{
		do_place(grid, &tetri[index], x, y);
		if (solve_core(grid, tetri, count, index + 1))
			return (1);
		remove_at(grid, &tetri[index], x, y);
		x++;
	}
	return (0);
}
