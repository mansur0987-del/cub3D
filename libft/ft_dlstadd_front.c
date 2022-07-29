/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armaxima <<armaxima@student.42.fr>>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 07:57:43 by armaxima          #+#    #+#             */
/*   Updated: 2022/06/06 12:26:32 by armaxima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstadd_front(t_dlist **dlst, t_dlist *new)
{
	t_dlist	*last;

	if (*dlst && new)
	{
		if ((*dlst)->next == NULL)
		{
			(*dlst)->next = new;
			new -> prev = *dlst;
		}
		else
		{
			last = (*dlst)->prev;
			last->next = new;
			new->prev = last;
		}
		new -> next = *dlst;
		(*dlst)->prev = new;
		*dlst = new;
	}
}
