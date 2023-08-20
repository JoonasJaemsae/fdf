/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjamsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 17:42:30 by jjamsa            #+#    #+#             */
/*   Updated: 2022/04/02 20:59:29 by jjamsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include "libft.h"
# include <fcntl.h>

typedef struct s_data
{
	int		x1;
	int		y1;
	int		x2;
	int		y2;
	int		start_x1;
	int		start_y1;
	int		start_x2;
	int		start_y2;
	int		distance;
	int		multiplier;
	int		row;
	int		mode;
	int		colour_key;
	int		**colours;
	char	***arr;
	void	*mlx;
	void	*win;
}				t_data;

int			deal_key(int key, t_data *data);
int			draw_line(t_data *data, int colour);
int			dx_larger_than_dy(t_data *data, int colour, int direction);
int			dy_larger_than_dx(t_data *data, int colour, int direction);
int			one_delta_is_negative(t_data *data, int colour);
int			read_file_into_array(int fd, t_data *start, char **argv);
int			start_elevated(t_data *prog);
int			start_isometric(t_data *prog);
int			start_reverse_isometric(t_data *prog);
int			start_sideview_horizontal(t_data *prog);
int			start_sideview_vertical(t_data *prog);
int			start_topdown(t_data *prog);
void		change_distance(int key, t_data *data);
void		change_mode(int key, t_data *data);
void		display_options(t_data *data);
void		free_3d_array(t_data *data);
void		free_allocated_memory(t_data *data);
void		free_colours(t_data *data);
t_data		initialize_temp(t_data *prog);

#endif
