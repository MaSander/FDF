/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaner- <msander-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 07:13:52 by coder             #+#    #+#             */
/*   Updated: 2022/10/08 08:27:55 by msaner-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_map.h"

void	save_lines(t_data *data, int fd)
{
	char	*line;
	t_point	*above;	
	int		y;

	y = 0;
	above = NULL;
	line = get_next_line(fd);
	data->points = NULL;
	while (line)
	{
		turn_line_into_nodes(&data->points, line, y, &above);
		if (!above)
			above = data->points;
		y++;
		ft_free(line);
		line = get_next_line(fd);
	}
}

void	read_map(t_data *data, char *file)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	data->map_width = count_points_in_line(line);
	data->map_height = 0;
	while (line)
	{
		data->map_height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	fd = open(file, O_RDONLY);
	save_lines(data, fd);
	close(fd);
}
