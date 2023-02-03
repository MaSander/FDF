/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaner- <msander-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 03:39:55 by msaner-           #+#    #+#             */
/*   Updated: 2022/10/08 08:46:44 by msaner-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_MAP_H
# define READ_MAP_H

# include "../fdf.h"
# include <fcntl.h>
# include <unistd.h>
# define BUFFER_SIZE 100

char	*get_next_line(int fd);
char	*ft_strnewline(const char *s);
int		count_points_in_line(char *line);
t_point	*create_point(int x, int y, char *z_color, t_point *above);
void	turn_line_into_nodes(t_point **lst, char *line, int y, t_point **above);
void	ft_lstadd_back(t_point **lst, t_point *new);
t_point	*ft_lstlast(t_point *lst);

#endif
