/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaner- <msander-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 09:08:22 by coder             #+#    #+#             */
/*   Updated: 2022/10/07 07:52:59 by msaner-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	move_x_y(int keycode, t_data *data)
{
	if (keycode == K_LEFT)
		data->axis = data->axis - 1;
	if (keycode == K_RIGHT)
		data->axis = data->axis + 1;
	if (keycode == K_UP)
		data->ordinate -= 1;
	if (keycode == K_DOWN)
		data->ordinate += 1;
}

int	end(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img.img);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	ft_lstclear(&data->points);
	exit(0);
	return (0);
}

int	mouse_hook(int var, int x, int y, t_data *data)
{
	if (var == 4)
	{
		data->scale = data->scale - 1;
		data->axis = data->axis + 1;
	}
	if (var == 5)
	{
		data->scale = data->scale + 1;
		data->axis = data->axis - 1;
	}
	x = x + y;
	return (1);
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == K_ESCAPE)
		end(data);
	if (keycode >= K_LEFT && keycode <= K_DOWN)
		move_x_y(keycode, data);
	return (1);
}

int	hooks(t_data *data)
{
	mlx_loop_hook(data->mlx_ptr, drawing, data);
	mlx_key_hook(data->win_ptr, &key_hook, data);
	mlx_hook(data->win_ptr, 17, 0L, &end, data);
	mlx_mouse_hook(data->win_ptr, &mouse_hook, data);
	mlx_loop(data->mlx_ptr);
	return (1);
}
