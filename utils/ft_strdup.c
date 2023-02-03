/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaner- <msander-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 07:31:38 by msaner-           #+#    #+#             */
/*   Updated: 2022/10/07 07:31:39 by msaner-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*ft_strdup(const char *s)
{
	char	*newstr;
	int		ssize;

	ssize = ft_strlen(s) + 1;
	newstr = ft_calloc(ssize);
	if (!newstr)
		return (NULL);
	ft_strlcpy(newstr, s, ssize);
	return (newstr);
}
