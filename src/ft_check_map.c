/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armaxima <<armaxima@student.42.fr>>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 12:05:52 by armaxima          #+#    #+#             */
/*   Updated: 2022/06/17 17:40:50 by armaxima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_check_array_map(char **map, int x)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (i != x || y != (int)ft_strlen(map[x - 1]))
	{
		y = 0;
		while (map[i][y])
		{
			if (map[i][y] != ' ' && map[i][y] != '1' && \
			(i == 0 || y == 0 || y == (int)ft_strlen(map[i]) - 1 \
			|| y >= (int)ft_strlen(map[i - 1]) || \
			y >= (int)ft_strlen(map[i + 1]) \
			|| i == x - 1 || map[i - 1][y] == ' ' || \
			map[i + 1][y] == ' ' || map[i][y - 1] == ' ' || \
			map[i][y + 1] == ' '))
				return (1);
			y++;
		}
		i++;
	}
	return (0);
}

int	ft_check_pers(char **map)
{
	int	i;
	int	y;
	int	g;

	i = 0;
	g = 0;
	while (map[i])
	{
		y = 0;
		while (map[i][y])
		{
			if (map[i][y] == 'N' || map[i][y] == 'S' \
			|| map[i][y] == 'E' || map[i][y] == 'W')
				g++;
			if (map[i][y] != ' ' && map[i][y] != '1' && \
			map[i][y] != '0' && map[i][y] != 'N' && \
			map[i][y] != 'S' && map[i][y] != 'E' && \
			map[i][y] != 'W' && map[i][y] != 'D' && \
			map[i][y] != 'Z' && map[i][y] != 'T')
				return (1);
			y++;
		}
		i++;
	}
	return (g - 1);
}

int	ft_check_color(t_img *up_down, int i)
{
	char	**sp_col;
	int		g;

	sp_col = ft_split(up_down->path, ',');
	if (sp_col == NULL)
		return (1);
	if (sp_col[0] == NULL || sp_col[1] == NULL || \
	sp_col[2] == NULL || sp_col[3] != NULL)
		return (1);
	while (++i < 3)
	{
		g = 0;
		while (sp_col[i][g] && ft_isdigit(sp_col[i][g]))
			g++;
		if (g > 3 || sp_col[i][g] || ft_atoi(sp_col[i]) < 0 \
		|| ft_atoi(sp_col[i]) > 255)
			return (1);
		up_down->col = (up_down->col << 8) + ft_atoi(sp_col[i]);
		free(sp_col[i]);
	}
	free(sp_col);
	return (0);
}

int	ft_check_door(char **map)
{
	int	i;
	int	y;

	i = 0;
	while (map[i])
	{
		y = 0;
		while (map[i][y] && map[i][y] != 'D')
			y++;
		if (map[i][y] && (i == 0 || y == 0))
			return (1);
		if (map[i][y] && \
		(map[i - 1][y] != '1' || map[i + 1][y] != '1') && \
		(map[i][y - 1] != '1' || map[i][y + 1] != '1'))
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_map(char **map, t_img *up, t_img *down)
{
	int	x;

	if (map == NULL || map[0] == NULL)
		return (1);
	x = 0;
	while (map[x])
		x++;
	if (x < 3)
		return (1);
	if (ft_check_array_map(map, x))
		return (1);
	if (ft_check_pers(map) || ft_check_door(map))
		return (1);
	if (ft_check_color(up, -1) || ft_check_color(down, -1))
		return (1);
	return (0);
}
