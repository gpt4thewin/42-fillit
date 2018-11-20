/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos_normalize.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 00:57:20 by juazouz           #+#    #+#             */
/*   Updated: 2018/11/20 14:44:18 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "fillit.h"

static int		get_min_x(t_point *point)
{
	int		min;
	int		i;

	i = 0;
	min = point[i].x;
	while (i < TETRIMINOS_SIZE)
	{
		if (point[i].x < min)
		{
			min = point[i].x;
		}
		i++;
	}
	return (min);
}

static int		get_min_y(t_point *point)
{
	int		min;
	int		i;

	i = 0;
	min = point[i].y;
	while (i < TETRIMINOS_SIZE)
	{
		if (point[i].y < min)
		{
			min = point[i].y;
		}
		i++;
	}
	return (min);
}

static void		vector_sub(t_point *point, int x, int y)
{
	point->x -= x;
	point->y -= y;
}

void			tetriminos_normalize(t_tetriminos *tetriminos)
{
	int		i;
	int		min_x;
	int		min_y;

	min_x = get_min_x((t_point*)&(tetriminos->points));
	min_y = get_min_y((t_point*)&(tetriminos->points));
	i = 0;
	while (i < TETRIMINOS_SIZE)
	{
		vector_sub(&tetriminos->points[i], min_x, min_y);
		i++;
	}
	tetriminos->width = tetriminos->points[TETRIMINOS_SIZE - 1].x + 1;
	tetriminos->height = tetriminos->points[TETRIMINOS_SIZE - 1].y + 1;
}
