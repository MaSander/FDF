/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexadecimal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaner- <msander-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 07:32:50 by msaner-           #+#    #+#             */
/*   Updated: 2022/10/08 07:21:48 by msaner-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	htoi(char *hexa)
{
	int	len;
	int	value;
	int	mult;

	value = 0;
	mult = 0;
	len = ft_strlen(hexa) - 1;
	while (len > 0)
	{
		if ('0' <= hexa[len] && hexa[len] <= '9')
			value += (hexa[len] - '0') * pow(16, mult);
		if ('a' <= hexa[len] && hexa[len] <= 'f')
			value += (hexa[len] - 'a' + 10) * pow(16, mult);
		if (hexa[len] == 'x')
			break ;
		len--;
		mult++;
	}
	return (value);
}
