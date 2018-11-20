/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 18:42:30 by juazouz           #+#    #+#             */
/*   Updated: 2018/11/20 11:48:39 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#define USAGE_TEXT "Usage : fillit <file>"

static int	read_file(char *path, char *buffer, int *file_size)
{
	int	fd;

	fd = open((char*)path, O_RDONLY);
	if (fd < 0)
		return (0);
	*file_size = read(fd, buffer, BUFFER_SIZE - 1);
	close(fd);
	if (*file_size < 0)
		return (0);
	buffer[*file_size] = '\0';

	return (1);
}

static int	tetriminos_count(int file_size, int *count)
{
	if ((file_size - INPUT_TETRIMINOS_SIZE) % (INPUT_TETRIMINOS_SIZE + 1) != 0)
		return (0);

	*count = ((file_size - INPUT_TETRIMINOS_SIZE) / (INPUT_TETRIMINOS_SIZE + 1)) + 1;
	return (1);
}

static int	validate(t_tetriminos *tetriminos, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (!tetriminos_validate(&tetriminos[i]))
			return (0);
		i++;
	}

	return (1);
}

static void	normalize(t_tetriminos *tetriminos, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		tetriminos_normalize(&tetriminos[i]);
		i++;
	}
}

static int	parse(char *filepath, t_tetriminos **tetriminos, int *count)
{
	char			buffer[BUFFER_SIZE];
	int				file_size;

	if (!read_file(filepath, buffer, &file_size) ||
		!tetriminos_count(file_size, count))
	{
		return (0);
	}
	*tetriminos = ft_memalloc(sizeof(t_tetriminos) * (*count));
	if (!input_parse(buffer, *tetriminos, *count) ||
		!validate(*tetriminos, *count))
	{
		return (0);
	}
	normalize(*tetriminos, *count);
	return (1);
}

int			main(int argc, char *argv[])
{
	t_tetriminos	*tetriminos;
	int				count;
	t_grid			*result;

	if (argc != 2)
	{
		ft_putendl(USAGE_TEXT);
		return (1);
	}
	if (!parse(argv[1], &tetriminos, &count))
	{
		error_invalid_input();
	}
	result = solve(tetriminos, count);
	if (result == NULL)
	{
		ft_putendl("(DEBUG) Could not find a solution");
		return (1);
	}
	print_grid(result);

	return (0);
}
