/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armaxima <<armaxima@student.42.fr>>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 13:58:38 by armaxima          #+#    #+#             */
/*   Updated: 2022/06/17 18:51:25 by armaxima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_paint_up_pol(t_dt *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < WIN_Y)
	{
		x = 0;
		while (x < WIN_X / 2)
		{
			ft_put_mlx_pixel(game, x, y, game->up->col);
			x++;
		}
		while (x < WIN_X)
		{
			ft_put_mlx_pixel(game, x, y, game->pol->col);
			x++;
		}
		y++;
	}
}

void	ft_min_pixel_put(t_dt *game, int x, int y, int col)
{
	int	i;
	int	g;

	i = x * 10;
	while (i < (x * 10) + 10)
	{
		g = y * 10;
		while (g < (y * 10) + 10)
		{
			ft_put_mlx_pixel(game, i, g, col);
			g++;
		}
		i++;
	}
}

void	ft_paint_small_map(t_dt *gm)
{
	int	x;
	int	y;

	x = 0;
	while (gm->data[x])
	{
		y = 0;
		while (gm->data[x][y])
		{
			if (gm->data[x][y] == '1')
				ft_min_pixel_put(gm, x, y, 0x0000ff);
			if (gm->data[x][y] == 'Z')
				ft_min_pixel_put(gm, x, y, 0xffa500);
			if (gm->data[x][y] == 'T')
				ft_min_pixel_put(gm, x, y, 0x808000);
			y++;
		}
		x++;
	}
	ft_put_mlx_pixel(gm, gm->pers->x * 10, gm->pers->y * 10, gm->pers->col);
}

int	ft_draw(t_dt *gm)
{
	gm->pers->sty = 0;
	gm->pers->stx = 0;
	gm->pers->direct = gm->data[gm->pers->x][gm->pers->y];
	mlx_clear_window(gm->win->mlx_ptr, gm->win->win_ptr);
	ft_paint_up_pol(gm);
	ft_ray(gm);
	ft_wall_paint(gm);
	ft_search_anime(gm);
	mlx_put_image_to_window(gm->win->mlx_ptr,
		gm->win->win_ptr, gm->win->img, 0, 0);
	return (0);
}
