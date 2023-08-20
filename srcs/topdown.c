/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   topdown.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjamsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 17:06:19 by jjamsa            #+#    #+#             */
/*   Updated: 2022/04/02 13:48:23 by jjamsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_data	initialize_temp(t_data *prog)
{
	t_data	temp;

	temp.x1 = prog->x1;
	temp.y1 = prog->y1;
	temp.x2 = prog->x2;
	temp.y2 = prog->y2;
	temp.mlx = prog->mlx;
	temp.win = prog->win;
	temp.row = prog->row;
	temp.colour_key = prog->colour_key;
	temp.colours = prog->colours;
	temp.arr = prog->arr;
	temp.distance = prog->distance;
	temp.multiplier = prog->multiplier;
	return (temp);
}

t_data	*initialize_topdown_row_start(t_data *dst, t_data src)
{
	dst->x1 = src.x1;
	dst->x2 = src.x2;
	dst->y1 = dst->y1 + src.distance;
	dst->y2 = dst->y1;
	return (dst);
}

int	init_line(t_data *temp, char **arr, char ch)
{
	int	c;

	c = temp->colour_key;
	if (ch == 'x')
		temp->x2 = temp->x2 + temp->distance;
	else if (ch == 'y')
		temp->y2 = temp->y2 + temp->distance;
	if (ft_atoi(*arr) != 0)
		draw_line(temp, temp->colours[c][1]);
	else
		draw_line(temp, temp->colours[c][0]);
	return (0);
}

void	handle_topdown_row(int i, t_data *prog)
{
	int		flag;
	int		j;
	t_data	temp;

	j = 0;
	flag = 0;
	while (prog->arr[i][j + 1] != 0 && prog->arr[i + 1] != 0)
	{
		temp = initialize_temp(prog);
		init_line(&temp, &(prog->arr[i][j]), 'x');
		temp = initialize_temp(prog);
		if (flag == 0 && prog->arr[i + 1][j] != 0)
			init_line(&temp, &(prog->arr[i][j]), 'y');
		else
			flag = 1;
		prog->x1 = prog->x1 + prog->distance;
		prog->x2 = prog->x1;
		j++;
	}
	if (flag == 0 && prog->arr[i + 1][j] != 0)
	{
		temp = initialize_temp(prog);
		init_line(&temp, &(prog->arr[i][j]), 'y');
	}
}

int	start_topdown(t_data *prog)
{
	int		i;
	int		j;
	t_data	temp;
	t_data	start;

	i = 0;
	start = initialize_temp(prog);
	prog = initialize_topdown_row_start(prog, start);
	while (prog->arr[i + 1] != 0)
	{
		handle_topdown_row(i, prog);
		prog = initialize_topdown_row_start(prog, start);
		i++;
	}
	j = 0;
	while (prog->arr[i][j + 1] != 0)
	{
		temp = initialize_temp(prog);
		init_line(&temp, &(prog->arr[i][j]), 'x');
		prog->x1 = prog->x1 + prog->distance;
		prog->x2 = prog->x1;
		j++;
	}
	return (0);
}
