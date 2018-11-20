/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_grid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 18:00:04 by juazouz           #+#    #+#             */
/*   Updated: 2018/11/20 12:04:30 by juazouz          ###   ########.fr       */
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
