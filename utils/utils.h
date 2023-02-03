/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaner- <msander-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 07:32:52 by msaner-           #+#    #+#             */
/*   Updated: 2022/10/08 07:28:10 by msaner-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stddef.h>
# include <stdlib.h>
# include "../fdf.h"

int		ft_atoi(const char *str);
int		htoi(char *hexa);
char	*ft_calloc(int size);
char	*ft_strdup(const char *s);
char	**ft_split(const char *s, char c);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strnstr(const char *big, const char *little, size_t len);
void	ft_free(void *ptr);
void	ft_free_array_char(char **ptr, int len);

#endif