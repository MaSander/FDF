/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msander- <msander-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 07:35:53 by msaner-           #+#    #+#             */
/*   Updated: 2023/07/23 12:21:01 by msander-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	start_window_with_image(t_data *data)
{
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->width, \
		data->height, data->window_name);
	data->img.img = mlx_new_image(data->mlx_ptr, data->width, data->height);
}

int	main(int argc, char **argv)
{
	t_data	data;
	// t_point	*point;

	if (argc == 1)
		return (0);
	if (!argv[2] || !ft_strnstr(argv[2], ".fdf", ft_strlen(argv[2])))
		return (0);
	read_map(&data, argv[2]);
	// point = data.points;
	data.window_name = argv[1];
	data.width = 800;
	data.height = 800;
	data.axis = 15;
	data.ordinate = 0;
	data.scale = 30;
	start_window_with_image(&data);
	data.img.addr = mlx_get_data_addr(data.img.img, &data.img.bpp, \
		&data.img.line_len, &data.img.endian);
	hooks(&data);
}
