/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armaxima <<armaxima@student.42.fr>>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 10:00:22 by armaxima          #+#    #+#             */
/*   Updated: 2022/06/06 12:28:38 by armaxima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t		i;

	i = 0;
	while (size > 1 && src[i])
	{
		dest[i] = src[i];
		size--;
		i++;
	}
	if (size > 0)
		dest[i] = '\0';
	return (ft_strlen(src));
}
