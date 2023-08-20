/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjamsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 15:55:04 by jjamsa            #+#    #+#             */
/*   Updated: 2022/04/02 20:08:32 by jjamsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	change_starting_coords(t_data *data, int direction)
{
	if (direction == 1)
	{
		data->start_x1 = data->start_x1 + 20;
		data->start_x2 = data->start_x2 + 20;
	}
	else if (direction == -1)
	{
		data->start_x1 = data->start_x1 - 20;
		data->start_x2 = data->start_x2 - 20;
	}
	else if (direction == 2)
	{
		data->start_y1 = data->start_y1 - 20;
		data->start_y2 = data->start_y2 - 20;
	}
	else if (direction == -2)
	{
		data->start_y1 = data->start_y1 + 20;
		data->start_y2 = data->start_y2 + 20;
	}
	data->x1 = data->start_x1;
	data->x2 = data->start_x2;
	data->y1 = data->start_y1;
	data->y2 = data->start_y2;
	data->row = 0;
}

void	move_picture(int key, t_data *data)
{
	int	direction;

	if (key == 123)
		direction = -1;
	if (key == 124)
		direction = 1;
	if (key == 125)
		direction = -2;
	if (key == 126)
		direction = 2;
	mlx_clear_window(data->mlx, data->win);
	change_starting_coords(data, direction);
	if (data->mode == 1)
		start_topdown(data);
	else if (data->mode == 2)
		start_isometric(data);
	else if (data->mode == 3)
		start_reverse_isometric(data);
	else if (data->mode == 4)
		start_sideview_horizontal(data);
	else if (data->mode == 5)
		start_sideview_vertical(data);
}

void	change_elevation(int key, t_data *data)
{
	if (key == 27)
		data->multiplier = data->multiplier - 1;
	else if (key == 24)
		data->multiplier = data->multiplier + 1;
	mlx_clear_window(data->mlx, data->win);
	if (data->mode == 1)
		start_topdown(data);
	else if (data->mode == 2)
		start_isometric(data);
	else if (data->mode == 3)
		start_reverse_isometric(data);
	else if (data->mode == 4)
		start_sideview_horizontal(data);
	else if (data->mode == 5)
		start_sideview_vertical(data);
}

void	change_colour_scheme(t_data *data)
{
	if (data->colour_key == 0)
		data->colour_key = 1;
	else if (data->colour_key == 1)
		data->colour_key = 2;
	else if (data->colour_key == 2)
		data->colour_key = 3;
	else if (data->colour_key == 3)
		data->colour_key = 4;
	else if (data->colour_key == 4)
		data->colour_key = 5;
	else if (data->colour_key == 5)
		data->colour_key = 0;
	mlx_clear_window(data->mlx, data->win);
	if (data->mode == 1)
		start_topdown(data);
	else if (data->mode == 2)
		start_isometric(data);
	else if (data->mode == 3)
		start_reverse_isometric(data);
	else if (data->mode == 4)
		start_sideview_horizontal(data);
	else if (data->mode == 5)
		start_sideview_vertical(data);
}

int	deal_key(int key, t_data *data)
{
	change_starting_coords(data, 0);
	if (key == 18 || key == 19 || key == 20 || key == 21 || key == 23)
		change_mode(key, data);
	else if (key == 8)
		change_colour_scheme(data);
	else if (key == 27 || key == 24)
		change_elevation(key, data);
	else if (key == 0 || key == 1)
		change_distance(key, data);
	else if (key == 123 || key == 124 || key == 125 || key == 126)
		move_picture(key, data);
	else if (key == 53)
	{
		mlx_clear_window(data->mlx, data->win);
		mlx_destroy_window(data->mlx, data->win);
		free_allocated_memory(data);
		exit(0);
	}
	else
		ft_putstr("No action assigned to key.\n");
	display_options(data);
	return (0);
}
