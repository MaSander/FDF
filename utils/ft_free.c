/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaner- <msander-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 07:31:32 by msaner-           #+#    #+#             */
/*   Updated: 2022/10/08 07:28:07 by msaner-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_free(void *ptr)
{
	if (ptr)
	{
		free(ptr);
		ptr = NULL;
	}
}

void	ft_free_array_char(char **ptr, int len)
{
	while (len-- > 0)
	{
		if (ptr[len])
			ft_free(ptr[len]);
	}
	ft_free(ptr);
}
