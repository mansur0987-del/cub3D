/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armaxima <<armaxima@student.42.fr>>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 10:26:36 by armaxima          #+#    #+#             */
/*   Updated: 2022/06/06 12:28:45 by armaxima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*res_str;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	res_str = ft_strdup(s);
	if (res_str)
	{
		i = 0;
		while (res_str[i])
		{
			res_str[i] = f(i, res_str[i]);
			i++;
		}
	}
	return (res_str);
}
