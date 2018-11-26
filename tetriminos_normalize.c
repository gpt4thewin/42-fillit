/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos_normalize.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 00:57:20 by juazouz           #+#    #+#             */
/*   Updated: 2018/11/26 13:29:17 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "fillit.h"

static int		get_min(t_point *point, int (f)(t_point*))
{
	int		min;
	int		i;

	min = f(&point[0]);
	i = 1;
	while (i < TETRIMINOS_SIZE)
	{
		if (f(&point[i]) < min)
			min = f(&point[i]);
		i++;
	}
	return (min);
}

static int		get_max(t_point *point, int (f)(t_point*))
{
	int		max;
	int		i;

	max = f(&point[0]);
	i = 1;
	while (i < TETRIMINOS_SIZE)
	{
		if (f(&point[i]) > max)
			max = f(&point[i]);
		i++;
	}
	return (max);
}

static int		get_x(t_point *point)
{
	return (point->x);
}

static int		get_y(t_point *point)
{
	return (point->y);
}

void			tetriminos_normalize(t_tetriminos *tetriminos)
{
	int		i;
	int		min_x;
	int		min_y;

	min_x = get_min(tetriminos->points, get_x);
	min_y = get_min(tetriminos->points, get_y);
	i = 0;
	while (i < TETRIMINOS_SIZE)
	{
		tetriminos->points[i].x -= min_x;
		tetriminos->points[i].y -= min_y;
		i++;
	}
	tetriminos->width = get_max(tetriminos->points, get_x) + 1;
	tetriminos->height = get_max(tetriminos->points, get_y) + 1;
}
