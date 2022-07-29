/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armaxima <<armaxima@student.42.fr>>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 11:51:09 by armaxima          #+#    #+#             */
/*   Updated: 2022/06/06 12:26:45 by armaxima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist	*ft_dlstmap(t_dlist *dlst, void *(*f)(void *), void (*del)(void *))
{
	t_dlist	*res_list;
	t_dlist	*new_elem;
	t_dlist	*start_node;

	if (!dlst || !f || !del)
		return (NULL);
	res_list = NULL;
	start_node = dlst;
	while (FT_TRUE)
	{
		new_elem = ft_dlstnew(f(dlst -> content));
		if (!new_elem)
		{
			ft_dlstclear(&res_list, del);
			return (NULL);
		}
		ft_dlstadd_back(&res_list, new_elem);
		dlst = dlst -> next;
		if (dlst == start_node || !dlst)
			break ;
	}
	return (res_list);
}
