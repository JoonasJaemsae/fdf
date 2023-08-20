/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oh_and_one_more_thing.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjamsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 16:17:13 by jjamsa            #+#    #+#             */
/*   Updated: 2022/04/02 16:47:04 by jjamsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	display_current_colour_scheme(t_data *data, void *mlx, void *win)
{
	if (data->colour_key == 0)
		mlx_string_put(mlx, win, 1260, 28, 0x00FFFFFF, "Plain White");
	if (data->colour_key == 1)
	{
		mlx_string_put(mlx, win, 1260, 28, 0x00FFFFFF, "El Cla");
		mlx_string_put(mlx, win, 1321, 28, 0x00FF0000, "ssico");
	}
	if (data->colour_key == 2)
	{
		mlx_string_put(mlx, win, 1260, 28, 0x00fff2cc, "Creme");
		mlx_string_put(mlx, win, 1320, 28, 0x00E77B0B, "Brulee");
	}
	if (data->colour_key == 3)
	{
		mlx_string_put(mlx, win, 1260, 28, 0x000080FF, "Baskin");
		mlx_string_put(mlx, win, 1330, 28, 0x00FF0096, "Robbins");
	}
	if (data->colour_key == 4)
	{
		mlx_string_put(mlx, win, 1260, 28, 0x00ffd966, "Tim Burton's");
		mlx_string_put(mlx, win, 1388, 28, 0x0023221e, "Batman");
	}
	if (data->colour_key == 5)
		mlx_string_put(mlx, win, 1260, 28, 0x00FFFFFF,
			"The Emperor's New Clothes");
}

void	display_current_values(t_data *data)
{
	int	white;

	white = 0x00FFFFFF;
	mlx_string_put(data->mlx, data->win, 1110, 10, white, "Mode: ");
	if (data->mode == 1)
		mlx_string_put(data->mlx, data->win, 1260, 10, white, "Topdown");
	if (data->mode == 2)
		mlx_string_put(data->mlx, data->win, 1260, 10, white, "Isometric 1");
	if (data->mode == 3)
		mlx_string_put(data->mlx, data->win, 1260, 10, white, "Isometric 2");
	if (data->mode == 4)
		mlx_string_put(data->mlx, data->win, 1260, 10, white,
			"Sideview from bottom");
	if (data->mode == 5)
		mlx_string_put(data->mlx, data->win, 1260, 10, white,
			"Sideview from right");
	mlx_string_put(data->mlx, data->win, 1110, 28, white, "Colour scheme: ");
	display_current_colour_scheme(data, data->mlx, data->win);
}

void	display_options(t_data *data)
{
	int	white;

	white = 0x00FFFFFF;
	mlx_string_put(data->mlx, data->win, 10, 10, white,
		"Change elevation of accented points:");
	mlx_string_put(data->mlx, data->win, 380, 10, white, "- +");
	mlx_string_put(data->mlx, data->win, 10, 28, white,
		"Change distance between 2D points:");
	mlx_string_put(data->mlx, data->win, 380, 28, white, "A S");
	mlx_string_put(data->mlx, data->win, 10, 46, white,
		"Move the picture around:");
	mlx_string_put(data->mlx, data->win, 380, 46, white, "Arrow Keys");
	mlx_string_put(data->mlx, data->win, 10, 64, white,
		"Toggle between perspective modes:");
	mlx_string_put(data->mlx, data->win, 380, 64, white, "1 2 3 4 5");
	mlx_string_put(data->mlx, data->win, 10, 82, white,
		"Switch between colour schemes:");
	mlx_string_put(data->mlx, data->win, 380, 82, white, "C");
	display_current_values(data);
}
