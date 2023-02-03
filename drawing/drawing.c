/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaner- <msander-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 03:44:23 by msaner-           #+#    #+#             */
/*   Updated: 2022/10/08 07:01:27 by msaner-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

typedef struct s_line
{
	int	x0;
	int	y0;
	int	z0;
	int	x1;
	int	y1;
	int	z1;
	int	color;
}	t_line;

void	render_background(t_data *data, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			pixel_drawing(data, j, i, color);
			j++;
		}
		++i;
	}
}

static	void	bresenham(t_line *line, t_data *data)
{
	t_point	delta;
	t_point	sign;
	int		error[2];

	delta.x = abs(line->x0 - line->x1);
	delta.y = abs(line->y0 - line->y1);
	sign.x = ternary_less_greater_than(line->x1, line->x0);
	sign.y = ternary_less_greater_than(line->y1, line->y0);
	error[0] = delta.x - delta.y;
	while (line->x1 != line->x0 || line->y1 != line->y0)
	{
		pixel_drawing(data, line->x1, line->y1, line->color);
		error[1] = error[0] * 2;
		if (error[1] > -delta.y)
		{
			error[0] -= delta.y;
			line->x1 += sign.x;
		}
		if (error[1] < delta.x)
		{
			error[0] += delta.x;
			line->y1 += sign.y;
		}
	}
}

void	iso(t_line *line)
{
	line->x0 = (line->x0 - line->y0) * cos(0.8);
	line->y0 = ((line->x0 + line->y0) * sin(0.8)) - (line->z0 * 0.5);
	line->x1 = (line->x1 - line->y1) * cos(0.8);
	line->y1 = ((line->x1 + line->y1) * sin(0.8)) - (line->z1 * 0.5);
}

void	drawing_line(t_point *start, t_point *end, t_data *data)
{
	t_line	line;

	line.x0 = (start->x + data->axis) * data->scale;
	line.y0 = (start->y + data->ordinate) * data->scale;
	line.z0 = start->z * data->scale;
	line.x1 = (end->x + data->axis) * data->scale;
	line.y1 = (end->y + data->ordinate) * data->scale;
	line.z1 = end->z * data->scale;
	if (end->color == 0)
		line.color = WHITE;
	else
		line.color = end->color;
	iso(&line);
	bresenham(&line, data);
}

int	drawing(t_data *data)
{
	int		line_i;
	t_point	*point;

	render_background(data, 0x000);
	point = data->points;
	line_i = 0;
	while (point)
	{
		if (point->above)
			drawing_line(point->above, point, data);
		if (point->next == NULL)
			break ;
		line_i++;
		if (line_i == data->map_width)
			line_i = 0;
		else
			drawing_line(point->next, point, data);
		point = point->next;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img, 0, 0);
	return (0);
}
