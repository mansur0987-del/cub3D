/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armaxima <<armaxima@student.42.fr>>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 09:58:23 by armaxima          #+#    #+#             */
/*   Updated: 2022/06/06 12:27:56 by armaxima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*dest_temp;
	const char	*src_temp;
	size_t		i;

	dest_temp = dest;
	src_temp = src;
	if (dest_temp < src_temp || (size_t)(dest_temp - src_temp) > n)
	{
		i = 0;
		while (i < n)
		{
			dest_temp[i] = src_temp[i];
			i++;
		}
	}
	else if (dest_temp > src_temp)
	{
		while (n > 0)
		{
			dest_temp[n - 1] = src_temp[n - 1];
			n--;
		}
	}
	return (dest);
}
