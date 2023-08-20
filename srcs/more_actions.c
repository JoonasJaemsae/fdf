/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_actions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjamsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 15:57:52 by jjamsa            #+#    #+#             */
/*   Updated: 2022/04/02 16:54:28 by jjamsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	change_distance(int key, t_data *data)
{
	if (key == 0)
	{
		if (data->distance > 2)
			data->distance = data->distance - 2;
	}
	else if (key == 1)
		data->distance = data->distance + 2;
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

void	change_mode(int key, t_data *data)
{
	if (data->mode != 1 && key == 18)
		data->mode = 1;
	if (data->mode != 2 && key == 19)
		data->mode = 2;
	if (data->mode != 3 && key == 20)
		data->mode = 3;
	if (data->mode != 4 && key == 21)
		data->mode = 4;
	if (data->mode != 5 && key == 23)
		data->mode = 5;
	mlx_clear_window(data->mlx, data->win);
	if (data->mode == 1 && key == 18)
		start_topdown(data);
	if (data->mode == 2 && key == 19)
		start_isometric(data);
	if (data->mode == 3 && key == 20)
		start_reverse_isometric(data);
	if (data->mode == 4 && key == 21)
		start_sideview_horizontal(data);
	if (data->mode == 5 && key == 23)
		start_sideview_vertical(data);
}

int	draw_line(t_data *data, int colour)
{
	int	dx;
	int	dy;

	dx = data->x2 - data->x1;
	dy = data->y2 - data->y1;
	if (dx == 0 && dy == 0)
		mlx_pixel_put(data->mlx, data->win, data->x1, data->y1, colour);
	else if (dx < 0 && dy < 0)
	{
		ft_swap(&(data->y1), &(data->y2));
		ft_swap(&(data->x1), &(data->x2));
		if ((dx * -1) > (dy * -1))
			dx_larger_than_dy(data, colour, 1);
		else
			dy_larger_than_dx(data, colour, 1);
	}
	else if (dx >= dy && dy >= 0)
		dx_larger_than_dy(data, colour, 1);
	else if (dy < 0 || dx < 0)
		one_delta_is_negative(data, colour);
	else if (dy > dx)
		dy_larger_than_dx(data, colour, 1);
	return (0);
}
