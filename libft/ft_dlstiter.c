/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstiter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armaxima <<armaxima@student.42.fr>>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 08:18:44 by armaxima          #+#    #+#             */
/*   Updated: 2022/06/06 12:26:48 by armaxima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstiter(t_dlist *dlst, void (*f)(void *))
{
	t_dlist	*start;

	if (!dlst || !f)
		return ;
	start = dlst;
	while (FT_TRUE)
	{
		if (dlst->content)
			f(dlst->content);
		dlst = dlst ->next;
		if (!dlst || dlst == start)
			break ;
	}
}
