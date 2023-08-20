/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_drawing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjamsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 15:55:51 by jjamsa            #+#    #+#             */
/*   Updated: 2022/04/02 16:59:51 by jjamsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	dx_negative_slope_below_1(t_data *data, int colour)
{
	int	x;
	int	y;
	int	dx;
	int	dy;
	int	p;

	x = data->x1;
	y = data->y1;
	dx = data->x1 - data->x2;
	dy = data->y2 - data->y1;
	p = 2 * dy - dx;
	while (x >= data->x2)
	{
		mlx_pixel_put(data->mlx, data->win, x, y, colour);
		x--;
		if (p < 0)
			p = p + (2 * dy);
		else if (p >= 0)
		{
			p = p + ((2 * dy) - (2 * dx));
			y++;
		}
	}
	return (0);
}

int	dy_negative_slope_above_1(t_data *data, int colour)
{
	int	x;
	int	y;
	int	dx;
	int	dy;
	int	p;

	x = data->x1;
	y = data->y1;
	dx = data->x2 - data->x1;
	dy = data->y1 - data->y2;
	p = 2 * dx - dy;
	while (y >= data->y2)
	{
		mlx_pixel_put(data->mlx, data->win, x, y, colour);
		y--;
		if (p < 0)
			p = p + (2 * dx);
		else if (p >= 0)
		{
			p = p + ((2 * dx) - (2 * dy));
			x++;
		}
	}
	return (0);
}

int	dx_larger_than_dy(t_data *data, int colour, int direction)
{
	int	x;
	int	y;
	int	dx;
	int	dy;
	int	p;

	x = data->x1;
	y = data->y1;
	dx = data->x2 - data->x1;
	dy = ft_abs(data->y2 - data->y1);
	p = 2 * dy - dx;
	while (x <= data->x2)
	{
		mlx_pixel_put(data->mlx, data->win, x, y, colour);
		x++;
		if (p < 0)
			p = p + (2 * dy);
		else if (p >= 0)
		{
			p = p + ((2 * dy) - (2 * dx));
			y = y + direction;
		}
	}
	return (0);
}

int	dy_larger_than_dx(t_data *data, int colour, int direction)
{
	int	x;
	int	y;
	int	dx;
	int	dy;
	int	p;

	x = data->x1;
	y = data->y1;
	dx = ft_abs(data->x2 - data->x1);
	dy = data->y2 - data->y1;
	p = 2 * dx - dy;
	while (y <= data->y2)
	{
		mlx_pixel_put(data->mlx, data->win, x, y, colour);
		y++;
		if (p < 0)
			p = p + (2 * dx);
		else if (p >= 0)
		{
			p = p + ((2 * dx) - (2 * dy));
			x = x + direction;
		}
	}
	return (0);
}

int	one_delta_is_negative(t_data *data, int colour)
{
	int	dx;
	int	dy;

	dx = data->x2 - data->x1;
	dy = data->y2 - data->y1;
	if (dy < 0 && ft_abs(dy) <= ft_abs(dx))
	{
		dx_larger_than_dy(data, colour, -1);
	}
	else if (dy < 0 && ft_abs(dy) > ft_abs(dx))
	{
		dy_negative_slope_above_1(data, colour);
	}
	else if (dx < 0 && ft_abs(dy) < ft_abs(dx))
	{
		dx_negative_slope_below_1(data, colour);
	}
	else if (dx < 0 && ft_abs(dy) >= ft_abs(dx))
	{
		dy_larger_than_dx(data, colour, -1);
	}
	return (0);
}
