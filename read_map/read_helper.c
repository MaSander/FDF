/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaner- <msander-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 03:39:51 by msaner-           #+#    #+#             */
/*   Updated: 2022/10/08 08:46:47 by msaner-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_map.h"

int	count_points_in_line(char *line)
{
	int		num;
	int		point;

	num = 0;
	if (!line)
		return (0);
	point = 0;
	while (*line)
	{
		if (*line != ' ' && point == 0)
		{
			num++;
			point = 1;
		}
		if (*line == ' ')
			point = 0;
		line++;
	}
	return (num);
}

void	split_z_color(char *z_color, t_point *point)
{
	char	**splited;

	if (!*z_color)
	{
		return ;
	}
	splited = ft_split(z_color, ',');
	point->z = ft_atoi(splited[0]);
	if (splited[1])
	{
		point->color = htoi(splited[1]);
		ft_free_array_char(splited, 2);
	}
	else
	{
		point->color = PURPLE;
		ft_free_array_char(splited, 1);
	}
}

t_point	*create_point(int x, int y, char *z_color, t_point *above)
{
	t_point	*point;

	point = malloc(sizeof(t_point));
	point->x = x;
	point->y = y;
	split_z_color(z_color, point);
	point->above = above;
	point->next = NULL;
	return (point);
}

void	turn_line_into_nodes(t_point **lst, char *line, int y, t_point **above)
{
	int		x;
	char	**line_splited;

	x = 0;
	line_splited = ft_split(line, ' ');
	while (line_splited[x])
	{
		if (!*lst)
			*lst = create_point(x, y, line_splited[x], NULL);
		else
			ft_lstadd_back(lst,
				create_point(x, y, line_splited[x], *above));
		if (*above)
			*above = (*above)->next;
		x++;
	}
	ft_free_array_char(line_splited, x);
}

char	*ft_strnewline(const char *s)
{
	while (*s != '\0')
	{
		if (*s == '\n')
			return ((char *)s);
		++s;
	}
	return (NULL);
}
