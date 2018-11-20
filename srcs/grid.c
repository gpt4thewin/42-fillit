/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 18:00:04 by juazouz           #+#    #+#             */
/*   Updated: 2018/11/20 11:08:33 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_grid		*create_grid(int size)
{
	t_grid	*grid;

	grid = malloc(sizeof(t_grid));
	if (grid == NULL)
		return (NULL);
	grid->size = size;
	grid->cells = ft_memalloc(sizeof(t_tetriminos*) * size * size);

	return (grid);
}

void		free_grid(t_grid *grid)
{
	if (grid->cells != NULL)
		free(grid->cells);
	free(grid);
}

static void	print_line(t_grid *grid, int y)
{
	int				i;
	t_tetriminos	*content;

	i = 0;
	while (i < grid->size)
	{
		content = CELL_AT(grid, i, y);
		if (content != NULL)
			ft_putchar(content->id + 'A');
		else
			ft_putchar('.');
		i++;
	}
	ft_putendl("");
}

void		print_grid(t_grid *grid)
{
	int	i;

	i = 0;
	while (i < grid->size)
	{
		print_line(grid, i);
		i++;
	}
	//debug
	ft_putendl("");
}
