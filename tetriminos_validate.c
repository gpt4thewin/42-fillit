/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos_validate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 18:02:40 by juazouz           #+#    #+#             */
/*   Updated: 2018/11/28 15:46:05 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		count_adjacent(t_tetriminos *tetriminos, t_point *p1)
{
	int		i;
	int		dist;
	t_point	*p2;
	int		n;

	i = 0;
	n = 0;
	while (i < TETRIMINOS_SIZE)
	{
		p2 = &tetriminos->points[i];
		dist = distance(p1, p2);
		if (dist == 1)
			n++;
		i++;
	}
	return (n);
}

int				tetriminos_validate(t_tetriminos *tetriminos)
{
	int		i;
	int		tmp;
	int		n;

	n = 0;
	i = 0;
	while (i < TETRIMINOS_SIZE)
	{
		tmp = count_adjacent(tetriminos, &tetriminos->points[i]);
		if (tmp < 1)
			return (0);
		n += tmp;
		i++;
	}
	return (n >= 6);
}
