/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaner- <msander-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 07:31:18 by msaner-           #+#    #+#             */
/*   Updated: 2022/10/07 07:31:27 by msaner-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_isdigit(int c)
{
	if (c > 47 && c < 58)
		return (2048);
	return (0);
}

int	ft_atoi(const char *str)
{
	int		s;
	int		number;
	int		signal;

	s = 0;
	number = 0;
	signal = 1;
	while ((str[s] >= 9 && str[s] <= 13) || str[s] == 32)
		s++;
	if (str[s] == '-' || str[s] == '+')
	{
		if (str[s] == '-')
			signal = -1;
		s++;
	}
	while (ft_isdigit(str[s]))
	{
		number = (number * 10) + (str[s] - 48);
		s++;
	}
	return (number * signal);
}
