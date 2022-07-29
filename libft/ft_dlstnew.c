/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armaxima <<armaxima@student.42.fr>>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 07:51:04 by armaxima          #+#    #+#             */
/*   Updated: 2022/06/06 12:26:55 by armaxima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist	*ft_dlstnew(void *data)
{
	t_dlist	*new_node;

	new_node = malloc(sizeof(t_dlist));
	if (!new_node)
		return (NULL);
	new_node -> content = data;
	new_node -> next = NULL;
	new_node -> prev = NULL;
	return (new_node);
}
