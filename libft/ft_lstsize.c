/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armaxima <<armaxima@student.42.fr>>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 14:17:36 by armaxima          #+#    #+#             */
/*   Updated: 2022/06/06 12:27:40 by armaxima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *list)
{
	int		i;
	t_list	*lst;

	i = 0;
	lst = list;
	while (lst)
	{
		lst = lst -> next;
		i++;
	}
	return (i);
}
