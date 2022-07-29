/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armaxima <<armaxima@student.42.fr>>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 08:08:54 by armaxima          #+#    #+#             */
/*   Updated: 2022/06/06 12:26:35 by armaxima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstadd_back(t_dlist **dlst, t_dlist *new)
{
	t_dlist	*last;

	if (dlst)
	{
		if (*dlst && new)
		{
			last = (*dlst);
			while (last->next)
				last = last->next;
			last->next = new;
			new->prev = last;
		}
		else
			*dlst = new;
	}
}
