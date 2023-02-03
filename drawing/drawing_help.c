/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_help.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaner- <msander-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 07:18:23 by msaner-           #+#    #+#             */
/*   Updated: 2022/10/08 07:00:24 by msaner-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	pixel_drawing(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && y >= 0 && x <= data->height && y <= data->width)
	{
		dst = data->img.addr + \
			(y * data->img.line_len + x * (data->img.bpp / 8));
		*(unsigned int *)dst = color;
	}
}

int	ternary_less_greater_than(int x, int y)
{
	if (x < y)
		return (1);
	return (-1);
}
