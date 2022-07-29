/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armaxima <<armaxima@student.42.fr>>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 10:30:09 by armaxima          #+#    #+#             */
/*   Updated: 2022/06/06 12:29:03 by armaxima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*substr;
	const char	*source;
	char		*dest;
	size_t		max_len;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	source = s + start;
	max_len = ft_strlen(source);
	if (max_len < len)
		len = max_len;
	substr = malloc(sizeof(*substr) * (len + 1));
	if (!substr)
		return (NULL);
	dest = substr;
	while (source && len--)
		*dest++ = *source++;
	*dest = '\0';
	return (substr);
}
