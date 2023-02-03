/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_point.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaner- <msander-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 03:39:44 by msaner-           #+#    #+#             */
/*   Updated: 2022/10/07 03:39:44 by msaner-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_map.h"

void	ft_lstadd_back(t_point **lst, t_point *new)
{
	t_point	*node;

	if (new)
	{
		if (*lst)
		{
			node = ft_lstlast(*lst);
			node->next = new;
		}
		else
			*lst = new;
	}
}

t_point	*ft_lstlast(t_point *lst)
{
	if (!lst)
		return (NULL);
	if (lst->next)
		lst = ft_lstlast(lst->next);
	return (lst);
}

void	ft_lstclear(t_point **lst)
{
	t_point	*node;

	while (*lst)
	{
		node = *lst;
		*lst = (*lst)->next;
		free(node);
	}
}
