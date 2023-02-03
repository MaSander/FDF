/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaner- <msander-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 07:32:47 by msaner-           #+#    #+#             */
/*   Updated: 2023/02/03 15:14:15 by msaner-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	strlen;
	char			*result;

	strlen = ft_strlen(s);
	if (start >= strlen)
		return (ft_strdup(""));
	else if (strlen <= len)
		len = strlen - start;
	result = ft_calloc(len + 1);
	if (!result)
		return (NULL);
	ft_strlcpy(result, s + start, len + 1);
	return (result);
}
