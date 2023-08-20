/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjamsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 13:07:01 by jjamsa            #+#    #+#             */
/*   Updated: 2022/04/02 14:11:27 by jjamsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_data	*initialize_isometric_row_start(t_data *dst, t_data *src)
{
	int	difference;
	int	row;

	row = src->row;
	difference = (ft_atoi(src->arr[row][0])
			- ft_atoi(src->arr[row + 1][0])) * src->multiplier;
	src->row = src->row + 1;
	dst->row = src->row;
	src->x1 = src->x1 - src->distance;
	src->x2 = src->x1;
	src->y1 = src->y1 + (src->distance / 2) + difference;
	src->y2 = src->y1;
	dst->x1 = src->x1;
	dst->x2 = dst->x1;
	dst->y1 = src->y1;
	dst->y2 = dst->y1;
	return (dst);
}

int	draw_iso_line(t_data *temp, char **now, char **next, char ch)
{
	int	c;
	int	difference;

	c = temp->colour_key;
	difference = (ft_atoi(*now) - ft_atoi(*next)) * temp->multiplier;
	if (ch == 'x')
	{
		temp->x2 = temp->x2 + temp->distance;
		temp->y2 = temp->y2 + (temp->distance / 2) + difference;
	}
	else if (ch == 'y')
	{
		temp->y2 = temp->y2 + (temp->distance / 2) + difference;
		temp->x2 = temp->x2 - temp->distance;
	}
	if (ft_atoi(*now) != 0)
		draw_line(temp, temp->colours[c][1]);
	else
		draw_line(temp, temp->colours[c][0]);
	return (0);
}

void	next_iso_x_point(t_data *prog, char **current, char **next)
{
	int	difference;

	difference = (ft_atoi(*current) - ft_atoi(*next)) * prog->multiplier;
	prog->x1 = prog->x1 + prog->distance;
	prog->x2 = prog->x1;
	prog->y1 = prog->y1 + (prog->distance / 2) + difference;
	prog->y2 = prog->y1;
}

void	handle_iso_row(int i, t_data *prog)
{
	int		flag;
	int		j;
	t_data	temp;

	j = 0;
	flag = 0;
	while (prog->arr[i][j + 1] != 0 && prog->arr[i + 1] != 0)
	{
		temp = initialize_temp(prog);
		draw_iso_line(&temp, &(prog->arr[i][j]), &(prog->arr[i][j + 1]), 'x');
		temp = initialize_temp(prog);
		if (flag == 0 && prog->arr[i + 1][j] != 0)
			draw_iso_line(&temp, &(prog->arr[i][j]),
				&(prog->arr[i + 1][j]), 'y');
		else
			flag = 1;
		next_iso_x_point(prog, &(prog->arr[i][j]), &(prog->arr[i][j + 1]));
		j++;
	}
	if (flag == 0 && prog->arr[i + 1][j] != 0)
	{
		temp = initialize_temp(prog);
		draw_iso_line(&temp, &(prog->arr[i][j]), &(prog->arr[i + 1][j]), 'y');
	}
}

int	start_isometric(t_data *prog)
{
	int		i;
	int		j;
	t_data	temp;
	t_data	start;

	i = 0;
	start = initialize_temp(prog);
	while (prog->arr[i + 1] != 0)
	{
		handle_iso_row(i, prog);
		prog = initialize_isometric_row_start(prog, &start);
		i++;
	}
	j = 0;
	while (prog->arr[i][j + 1] != 0)
	{
		temp = initialize_temp(prog);
		draw_iso_line(&temp, &(prog->arr[i][j]), &(prog->arr[i][j + 1]), 'x');
		next_iso_x_point(prog, &(prog->arr[i][j]), &(prog->arr[i][j + 1]));
		j++;
	}
	return (0);
}
