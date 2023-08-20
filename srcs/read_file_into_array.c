/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file_into_array.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjamsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 18:03:42 by jjamsa            #+#    #+#             */
/*   Updated: 2022/04/02 20:56:50 by jjamsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	open_close_samba(int fd, char **argv)
{
	fd = close(fd);
	if (fd == -1)
	{
		write(2, "close() error.\n", 15);
		return (-1);
	}
	fd = open(argv[1], O_RDWR | O_APPEND);
	if (fd == -1)
	{
		write(2, "open() error.\n", 14);
		return (-1);
	}
	return (0);
}

int	allocate_and_fill_arrays(int fd, char *line, t_data *start, int array_count)
{
	int	i;
	int	word_count;

	i = 0;
	word_count = 0;
	start->arr = (char ***) malloc(sizeof(char **) * (array_count + 1));
	if (start->arr == NULL)
		return (-1);
	while (get_next_line(fd, &line) == 1)
	{
		word_count = ft_word_count(line, ' ');
		start->arr[i] = ft_strsplit(line, ' ');
		if (start->arr[i] == NULL)
		{
			free_3d_array(start);
			return (-1);
		}
		i++;
	}
	start->arr[i] = 0;
	return (0);
}

int	read_file_into_array(int fd, t_data *start, char **argv)
{
	int		word_count;
	int		lines;
	char	*line;

	line = NULL;
	lines = 0;
	while (get_next_line(fd, &line) == 1)
	{
		lines++;
		word_count = ft_word_count(line, ' ');
	}
	if (open_close_samba(fd, argv) == -1)
		return (-1);
	if (allocate_and_fill_arrays(fd, line, start, lines) == -1)
		return (-1);
	return (0);
}
