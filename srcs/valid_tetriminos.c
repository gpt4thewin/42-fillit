/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_tetriminos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 22:09:45 by marvin            #+#    #+#             */
/*   Updated: 2018/10/23 22:09:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		has_adjacent(t_tetriminos *tetriminos, t_point *p1)
{
	int		i;
	int		dist;
	t_point	*p2;

	i = 0;
	while (i < TETRIMINOS_SIZE)
	{
		p2 = &tetriminos->points[i];
		dist = ABS(p2->x - p1->x) + ABS(p2->y - p1->y);
		if (dist == 1)
			return (1);
		i++;
	}

	return (0);
}

int				validate_tetriminos(t_tetriminos *tetriminos)
{
	int		i;

	i = 0;
	while (i < TETRIMINOS_SIZE)
	{
		if (!has_adjacent(tetriminos, &tetriminos->points[i]))
			return (0);
		i++;
	}

	return (1);
}
