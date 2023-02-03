/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaner- <msander-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 07:32:36 by msaner-           #+#    #+#             */
/*   Updated: 2022/10/07 07:41:44 by msaner-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	i;

	i = 0;
	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (dstlen >= size)
		return (size + srclen);
	while (((i + dstlen) < size) && (src[i]))
	{
		dst[dstlen + i] = src[i];
		i++;
	}
	if (size == (i + dstlen))
		dst[i + dstlen - 1] = '\0';
	dst[i + dstlen] = '\0';
	return (dstlen + srclen);
}
