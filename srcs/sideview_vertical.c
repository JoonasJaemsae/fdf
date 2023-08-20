/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sideview_vertical.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjamsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 11:34:55 by jjamsa            #+#    #+#             */
/*   Updated: 2022/04/02 15:24:15 by jjamsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_data	*initialize_sideview_vertical_row_start(t_data *dst, t_data *src)
{
	int	difference;
	int	row;

	row = src->row;
	difference = (ft_atoi(src->arr[row][0])
			- ft_atoi(src->arr[row + 1][0])) * src->multiplier;
	src->row = src->row + 1;
	dst->row = src->row;
	src->y1 = src->y1 + difference;
	src->y2 = src->y1;
	src->x1 = src->x1 - src->distance;
	src->x2 = src->x1;
	dst->x1 = src->x1;
	dst->x2 = src->x2;
	dst->y1 = src->y1;
	dst->y2 = src->y2;
	return (dst);
}

int	sv_ver_line(t_data *temp, char **now, char **next, char ch)
{
	int	c;
	int	difference;

	c = temp->colour_key;
	difference = (ft_atoi(*now) - ft_atoi(*next)) * temp->multiplier;
	if (ch == 'x')
	{
		temp->x2 = temp->x1;
		temp->y2 = temp->y2 + difference;
	}
	else if (ch == 'y')
	{
		temp->x2 = temp->x2 - temp->distance;
		temp->y2 = temp->y2 + difference;
	}
	if (ft_atoi(*now) != 0)
		draw_line(temp, temp->colours[c][1]);
	else
		draw_line(temp, temp->colours[c][0]);
	return (0);
}

void	next_sv_v_x_point(t_data *prog, char **current, char **next)
{
	int	difference;

	difference = (ft_atoi(*current) - ft_atoi(*next)) * prog->multiplier;
	prog->x1 = prog->x1;
	prog->x2 = prog->x1;
	prog->y1 = prog->y1 + difference;
	prog->y2 = prog->y1;
}

void	handle_sideview_vertical_row(int i, t_data *prog)
{
	int		flag;
	int		j;
	t_data	temp;

	j = 0;
	flag = 0;
	while (prog->arr[i][j + 1] != 0 && prog->arr[i + 1] != 0)
	{
		temp = initialize_temp(prog);
		sv_ver_line(&temp, &(prog->arr[i][j]), &(prog->arr[i][j + 1]), 'x');
		if (flag == 0 && prog->arr[i + 1][j] != 0)
		{
			temp = initialize_temp(prog);
			sv_ver_line(&temp, &(prog->arr[i][j]), &(prog->arr[i + 1][j]), 'y');
		}
		else
			flag = 1;
		next_sv_v_x_point(prog, &(prog->arr[i][j]), &(prog->arr[i][j + 1]));
		j++;
	}
	if (flag == 0 && prog->arr[i + 1][j] != 0)
	{
		temp = initialize_temp(prog);
		sv_ver_line(&temp, &(prog->arr[i][j]), &(prog->arr[i + 1][j]), 'y');
	}
}

int	start_sideview_vertical(t_data *prog)
{
	int		i;
	int		j;
	t_data	temp;
	t_data	start;

	i = 0;
	start = initialize_temp(prog);
	while (prog->arr[i + 1] != 0)
	{
		handle_sideview_vertical_row(i, prog);
		prog = initialize_sideview_vertical_row_start(prog, &start);
		i++;
	}
	j = 0;
	while (prog->arr[i][j + 1] != 0)
	{
		temp = initialize_temp(prog);
		sv_ver_line(&temp, &(prog->arr[i][j]), &(prog->arr[i][j + 1]), 'x');
		next_sv_v_x_point(prog, &(prog->arr[i][j]), &(prog->arr[i][j + 1]));
		j++;
	}
	return (0);
}
