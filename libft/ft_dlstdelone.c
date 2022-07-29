/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdelone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armaxima <<armaxima@student.42.fr>>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 14:08:11 by armaxima          #+#    #+#             */
/*   Updated: 2022/06/06 16:04:27 by armaxima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstdelone(t_dlist **dlst, void (*del)(void *))
{
	t_dlist	*next_node;
	t_dlist	*last_node;

	next_node = NULL;
	if (del && dlst && *dlst)
	{
		if (ft_dlstsize(*dlst) > 1)
		{
			next_node = (*dlst)->next;
			last_node = (*dlst)->prev;
			last_node -> next = next_node;
			next_node -> prev = last_node;
		}
		if ((*dlst)->content)
			(*del)((*dlst)->content);
		free(*dlst);
		*dlst = next_node;
	}
}
