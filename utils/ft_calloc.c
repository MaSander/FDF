/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaner- <msander-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 07:31:26 by msaner-           #+#    #+#             */
/*   Updated: 2022/10/07 07:31:27 by msaner-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*ft_calloc(int size)
{
	char	*result;

	result = (char *)malloc(size);
	if (!result)
		return (NULL);
	while (--size >= 0)
		result[size] = '\0';
	return (result);
}
