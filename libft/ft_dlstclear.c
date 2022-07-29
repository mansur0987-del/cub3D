/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstclear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armaxima <<armaxima@student.42.fr>>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 07:44:13 by armaxima          #+#    #+#             */
/*   Updated: 2022/06/06 12:26:42 by armaxima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstclear(t_dlist **dlst, void (*del)(void *))
{
	t_dlist	*tmp;

	while (*dlst)
	{
		if ((*dlst)->content)
			del((*dlst)->content);
		tmp = *dlst;
		*dlst = tmp->next;
		free(tmp);
	}
	dlst = NULL;
}
