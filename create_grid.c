/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_grid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 18:00:04 by juazouz           #+#    #+#             */
/*   Updated: 2018/11/28 15:47:21 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_grid		*create_grid(int size)
{
	t_grid	*grid;

	grid = ft_safemalloc(sizeof(t_grid));
	grid->size = size;
	grid->cells = ft_safemalloc(sizeof(t_tetriminos*) * size * size);
	return (grid);
}
