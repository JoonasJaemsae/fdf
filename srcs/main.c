/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjamsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 16:16:06 by jjamsa            #+#    #+#             */
/*   Updated: 2022/04/02 20:58:51 by jjamsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	assign_colours_to_slots(t_data *data)
{
	data->colours[0][0] = 0x00FFFFFF;
	data->colours[0][1] = 0x00FFFFFF;
	data->colours[1][0] = 0x00FFFFFF;
	data->colours[1][1] = 0x00FF0000;
	data->colours[2][0] = 0x00fff2cc;
	data->colours[2][1] = 0x00E77B0B;
	data->colours[3][0] = 0x0068beff;
	data->colours[3][1] = 0x00FF0096;
	data->colours[4][0] = 0x00ffd966;
	data->colours[4][1] = 0x0023221e;
	data->colours[5][0] = 0x00000000;
	data->colours[5][1] = 0x00000000;
}

int	initialize_colour_schemes(t_data *data)
{
	int	i;

	i = 0;
	data->colours = (int **) malloc(sizeof(int *) * 6);
	if (data->colours == NULL)
		return (-1);
	while (i < 6)
	{
		data->colours[i] = (int *) malloc(sizeof(int) * 2);
		if (data->colours[i] == NULL)
		{
			free_colours(data);
			return (-1);
		}
		i++;
	}
	assign_colours_to_slots(data);
	return (0);
}

void	initialize_start(t_data *start)
{
	start->x1 = 400;
	start->y1 = 500;
	start->x2 = 400;
	start->y2 = 500;
	start->row = 0;
	start->start_x1 = 400;
	start->start_y1 = 500;
	start->start_x2 = 400;
	start->start_y2 = 500;
	start->colour_key = 0;
	start->multiplier = 1;
	start->mode = 2;
	start->distance = 20;
}

int	initial_setup(t_data *start, int argc, char **argv)
{
	int	fd;

	start->mlx = mlx_init();
	start->win = mlx_new_window(start->mlx, 1600, 1000, "fdf");
	if (start->win == NULL)
	{
		write(2, "Error: mlx_new_window returned NULL\n", 36);
		return (-1);
	}
	if (argc == 2)
	{
		fd = open(argv[1], O_RDWR | O_APPEND);
		if (fd == -1)
		{
			write(2, "open() error.\n", 14);
			return (-1);
		}
	}
	else
	{
		write(2, "Wrong number of arguments.\n", 26);
		return (-1);
	}
	return (fd);
}

int	main(int argc, char **argv)
{
	int		fd;
	t_data	start;

	fd = initial_setup(&start, argc, argv);
	if (fd == -1)
		exit (EXIT_FAILURE);
	if (read_file_into_array(fd, &start, argv) == -1)
		exit (EXIT_FAILURE);
	if (initialize_colour_schemes(&start) == -1)
		exit (EXIT_FAILURE);
	initialize_start(&start);
	display_options(&start);
	start_isometric(&start);
	mlx_key_hook(start.win, deal_key, &start);
	mlx_loop(start.mlx);
	return (0);
}
