/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 19:13:51 by juazouz           #+#    #+#             */
/*   Updated: 2018/11/28 15:46:47 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int			parse_line(char *str, int y, t_tetriminos *tetri)
{
	int	i;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		if (str[i] == '#')
		{
			if (tetri->points_count >= TETRIMINOS_SIZE)
				return (0);
			tetri->points[tetri->points_count].x = i;
			tetri->points[tetri->points_count].y = y;
			tetri->points_count++;
		}
		else if (str[i] != '.')
		{
			return (0);
		}
		i++;
	}
	return (i == INPUT_LINE_LEN);
}

static int			parse_tetriminos(char *input, t_tetriminos *tetri)
{
	int	i;

	i = 0;
	while (i < TETRIMINOS_SIZE)
	{
		if (!parse_line(input, i, tetri))
		{
			return (0);
		}
		input += INPUT_LINE_LEN + 1;
		i++;
	}
	return (tetri->points_count == TETRIMINOS_SIZE);
}

int					input_parse(char *input, t_tetriminos *tetri, int count)
{
	int	i;

	i = 0;
	while (1)
	{
		if (!parse_tetriminos(input, &tetri[i]))
		{
			return (0);
		}
		tetri[i].id = i;
		input += INPUT_TETRIMINOS_SIZE;
		i++;
		if (i >= count)
			return (1);
		if (*input != '\n')
			return (0);
		input++;
	}
	return (1);
}
