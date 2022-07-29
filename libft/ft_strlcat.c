/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armaxima <<armaxima@student.42.fr>>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 10:03:22 by armaxima          #+#    #+#             */
/*   Updated: 2022/06/06 12:28:41 by armaxima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	n;

	i = 0;
	n = 0;
	while (i < size && dst[i])
		i++;
	while (src[n] && ((i + n + 1) < size))
	{
		dst[i + n] = src[n];
		n++;
	}
	if (i < size)
		dst[i + n] = '\0';
	return (i + ft_strlen(src));
}
