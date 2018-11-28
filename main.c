/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 18:42:30 by juazouz           #+#    #+#             */
/*   Updated: 2018/11/28 15:46:30 by juazouz          ###   ########.fr       */
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
	*count =
		((file_size - INPUT_TETRIMINOS_SIZE) / (INPUT_TETRIMINOS_SIZE + 1)) + 1;
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

static int	parse(char *filepath, t_tetriminos **tetri, int *count)
{
	char	buffer[BUFFER_SIZE];
	int		file_size;
	int		i;

	if (!read_file(filepath, buffer, &file_size) ||
		!tetriminos_count(file_size, count))
	{
		return (0);
	}
	*tetri = ft_safemalloc(sizeof(t_tetriminos) * (*count));
	if (!input_parse(buffer, *tetri, *count) ||
		!validate(*tetri, *count))
	{
		return (0);
	}
	i = 0;
	while (i < *count)
	{
		tetriminos_normalize(&(*tetri)[i]);
		i++;
	}
	return (1);
}

int			main(int argc, char *argv[])
{
	t_tetriminos	*tetri;
	int				count;
	t_grid			*result;

	if (argc != 2)
	{
		ft_putendl(USAGE_TEXT);
		return (1);
	}
	if (!parse(argv[1], &tetri, &count))
	{
		ft_putendl(ERROR_MSG);
		return (1);
	}
	result = solve(tetri, count);
	print_grid(result);
	free_grid(result);
	return (0);
}
