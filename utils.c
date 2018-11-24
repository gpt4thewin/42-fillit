/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 12:59:46 by juazouz           #+#    #+#             */
/*   Updated: 2018/11/24 17:20:21 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		ft_abs(int n)
{
	return (n > 0 ? n : -n);
}

int				in_bounds(t_grid *grid, int x, int y)
{
	return (x < grid->size && y < grid->size);
}

t_tetriminos	*cell_at(t_grid *grid, int x, int y)
{
	return (grid->cells[x + grid->size * y]);
}

void			set_cell_at(t_grid *grid, int x, int y, t_tetriminos *val)
{
	(grid->cells[x + grid->size * y]) = val;
}

int				cells_count(t_grid *grid)
{
	return (grid->size * grid->size);
}

int				distance(t_point *a, t_point *b)
{
	return (ft_abs(a->x - b->x) + ft_abs(a->y - b->y));
}
