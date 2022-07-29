/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armaxima <<armaxima@student.42.fr>>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 09:41:01 by armaxima          #+#    #+#             */
/*   Updated: 2022/06/06 12:27:48 by armaxima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*dest;
	size_t	i;

	dest = s;
	i = 0;
	while (i < n)
	{
		*dest = (char) c;
		dest++;
		i++;
	}
	return (s);
}
