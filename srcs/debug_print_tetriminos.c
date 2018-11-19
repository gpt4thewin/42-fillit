/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_print_tetriminos.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 01:30:06 by juazouz           #+#    #+#             */
/*   Updated: 2018/11/19 11:44:58 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int any_point_at(t_tetriminos *tetriminos, int x, int y)
{
	t_point *point;
	int		i;

	i = 0;
	while (i < TETRIMINOS_SIZE)
	{
		point = &tetriminos->points[i];
		if (point->x == x && point->y == y)
			return (1);
		i++;
	}
	return (0);
}

static void	print_line(t_tetriminos *tetriminos, int y)
{
	int	i;

	i = 0;
	while (i < INPUT_LINE_LEN)
	{
		if (any_point_at(tetriminos, i, y))
			ft_putchar('#');
		else
			ft_putchar('.');
		i++;
	}
	ft_putendl("");
}

void		debug_print_tetriminos(t_tetriminos *tetriminos)
{
	int	i;

	i = 0;
	while (i < TETRIMINOS_SIZE)
	{
		print_line(tetriminos, i);
		i++;
	}
	ft_putendl("");
}
