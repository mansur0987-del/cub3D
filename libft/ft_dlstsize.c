/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstsize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armaxima <<armaxima@student.42.fr>>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 08:12:31 by armaxima          #+#    #+#             */
/*   Updated: 2022/06/06 12:26:52 by armaxima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_dlstsize(t_dlist *dlst)
{
	size_t	size;
	t_dlist	*start;

	if (!dlst)
		return (0);
	size = 1;
	start = dlst;
	dlst = dlst->next;
	while (dlst && dlst != start)
	{
		dlst = dlst ->next;
		size++;
	}
	return (size);
}
