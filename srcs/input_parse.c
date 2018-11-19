/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 19:13:51 by juazouz           #+#    #+#             */
/*   Updated: 2018/11/19 12:49:05 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int			parse_line(char *str, int y, t_tetriminos *tetriminos)
{
	int	i;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		if (str[i] == '#')
		{
			if (tetriminos->points_count >= TETRIMINOS_SIZE)
				return (0);
			tetriminos->points[tetriminos->points_count].x = i;
			tetriminos->points[tetriminos->points_count].y = y;
			tetriminos->points_count++;
			// debug
			printf("point %d,%d\n", i, y);
		}
		else if (str[i] != '.')
		{
			ft_putendl("Input : Invalid character");
			return (0);
		}
		i++;
	}
	return (i == INPUT_LINE_LEN);
}

static int			parse_tetriminos(char *input, t_tetriminos *tetriminos)
{
	int	i;

	i = 0;
	while (i < TETRIMINOS_SIZE)
	{
		if (!parse_line(input, i, tetriminos))
		{
			ft_putendl("Input : Invalid line");
			return (0);
		}
		input += INPUT_LINE_LEN + 1;
		i++;
	}
	return (tetriminos->points_count == TETRIMINOS_SIZE);
}

int					input_parse(char *input, t_tetriminos *tetriminos, int count)
{
	int	i;

	i = 0;
	while (1)
	{
		if (!parse_tetriminos(input, &tetriminos[i]))
		{
			ft_putendl("Input : Invalid tetriminos");
			return (0);
		}
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
