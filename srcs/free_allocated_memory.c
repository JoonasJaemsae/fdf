/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_allocated_memory.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjamsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 17:33:20 by jjamsa            #+#    #+#             */
/*   Updated: 2022/04/02 20:10:29 by jjamsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_3d_array(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->arr[i] != 0)
	{
		j = 0;
		while ((data->arr)[i][j] != 0)
		{
			free((data->arr)[i][j]);
			j++;
		}
		free((data->arr)[i]);
		i++;
	}
	free(data->arr);
}

void	free_colours(t_data *data)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		free(data->colours[i]);
		i++;
	}
	free(data->colours);
}

void	free_allocated_memory(t_data *data)
{
	free_colours(data);
	free_3d_array(data);
}
