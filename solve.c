/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 17:49:23 by juazouz           #+#    #+#             */
/*   Updated: 2018/11/20 12:57:33 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_grid	*solve_with_grid_size(t_tetriminos *tetri,
										int count,
										int grid_size)
{
	t_grid	*grid;

	grid = create_grid(grid_size);
	if (solve_core(grid, tetri, count, 0))
		return (grid);
	free_grid(grid);
	return (NULL);
}

t_grid			*solve(t_tetriminos *tetri, int count)
{
	int		i;
	t_grid	*result;

	i = 1;
	while (i < GRID_SIZE_LIMIT)
	{
		result = solve_with_grid_size(tetri, count, i);
		if (result != NULL)
			return (result);
		i++;
	}
	return (NULL);
}
