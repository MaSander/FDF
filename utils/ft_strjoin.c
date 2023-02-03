/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaner- <msander-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 07:31:42 by msaner-           #+#    #+#             */
/*   Updated: 2022/10/08 08:43:44 by msaner-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i1;
	int		i2;
	char	*str;

	if ((!s1 || !s2) || !*s2)
		return (NULL);
	i1 = ft_strlen(s1);
	i2 = ft_strlen(s2);
	str = ft_calloc(i1 + i2 + 1);
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, i1 + 1);
	ft_strlcat(str, s2, (i2 + i1 + 1));
	return (str);
}
