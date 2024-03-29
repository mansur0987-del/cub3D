/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armaxima <<armaxima@student.42.fr>>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 19:02:43 by armaxima          #+#    #+#             */
/*   Updated: 2022/06/06 12:28:55 by armaxima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_inset(char ch, char const *set)
{
	while (*set)
	{
		if (ch == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	finish;
	size_t	len;
	char	*trim_str;

	if (!s1 || !set)
		return (NULL);
	if (*s1)
	{
		start = 0;
		while (is_inset(s1[start], set) && s1[start])
			start++;
		finish = ft_strlen(s1);
		while (finish > start && is_inset(s1[finish - 1], set))
			finish--;
		len = finish - start;
		trim_str = ft_substr(s1, start, len);
	}
	else
		trim_str = ft_substr(s1, 2, 2);
	return (trim_str);
}
