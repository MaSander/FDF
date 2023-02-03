/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaner- <msander-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 02:36:07 by coder             #+#    #+#             */
/*   Updated: 2022/10/08 08:13:05 by msaner-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define K_ESCAPE	0xff1b
# define K_LEFT		0xff51
# define K_UP		0xff52
# define K_RIGHT	0xff53
# define K_DOWN		0xff54
# define WHITE		0xFFFFFF
# define PURPLE		0xE600FF

# include <mlx.h>
# include <stdlib.h>
# include <math.h>
# include "./utils/utils.h"

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_point
{
	int				x;
	int				y;
	int				z;
	int				color;
	struct s_point	*above;
	struct s_point	*next;
}	t_point;

typedef struct s_data
{
	char	*window_name;
	int		width;
	int		height;
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	t_point	*points;
	int		map_width;
	int		map_height;
	int		axis;
	int		ordinate;
	int		scale;
}	t_data;

int		hooks(t_data *data);
int		key_hook(int keycode, t_data *data);
int		drawing(t_data *data);
void	drawing_line(t_point *start, t_point *end, t_data *data);
void	pixel_drawing(t_data *data, int x, int y, int color);
void	render_background(t_data *data, int color);
void	ft_lstclear(t_point **lst);
void	read_map(t_data *data, char *file);
int		ternary_less_greater_than(int x, int y);

#endif
