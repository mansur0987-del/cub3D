/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnchar_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armaxima <<armaxima@student.42.fr>>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 14:12:38 by armaxima          #+#    #+#             */
/*   Updated: 2022/06/06 12:27:59 by armaxima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_putnchar_fd(size_t n, char ch, int fd)
{
	size_t	i;

	i = 0;
	if (n > 0)
	{
		while (i < n)
		{
			ft_putchar_fd(ch, fd);
			i++;
		}
	}
	return (i);
}
