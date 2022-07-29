/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armaxima <<armaxima@student.42.fr>>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 10:18:56 by armaxima          #+#    #+#             */
/*   Updated: 2022/06/06 12:28:50 by armaxima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char *str, const char *find, size_t n)
{
	size_t		find_len;
	size_t		i;

	find_len = ft_strlen(find);
	if (find_len == 0)
		return (str);
	if (*str == '\0')
		return (0);
	if (find_len > n)
		return (0);
	i = 0;
	while (i <= (n - find_len))
	{
		if ((str[0] == find[0]) && (ft_strncmp(str, find, find_len) == 0))
			return ((char *) str);
		str++;
		i++;
	}
	return (0);
}
