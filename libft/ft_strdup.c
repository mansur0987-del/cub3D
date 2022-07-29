/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armaxima <<armaxima@student.42.fr>>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 10:28:05 by armaxima          #+#    #+#             */
/*   Updated: 2022/06/06 12:28:11 by armaxima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*dup_str;

	dup_str = malloc((ft_strlen(s) + 1) * sizeof(*s));
	if (dup_str)
	{
		i = -1;
		while (s[++i])
			dup_str[i] = s[i];
		dup_str[i] = '\0';
	}
	return (dup_str);
}
