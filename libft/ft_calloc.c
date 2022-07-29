/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armaxima <<armaxima@student.42.fr>>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 12:22:23 by armaxima          #+#    #+#             */
/*   Updated: 2022/06/06 12:22:25 by armaxima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	char	*res;

	if (n == 0 || size == 0)
	{
		n = 1;
		size = 1;
	}
	size = size * n;
	res = malloc(size);
	if (res)
		ft_bzero(res, size);
	return (res);
}
