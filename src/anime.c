/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anime.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarg <kmarg@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 00:09:16 by kmarg             #+#    #+#             */
/*   Updated: 2022/06/19 07:25:06 by kmarg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	risovalka(t_dt *gm)
{
	int	x;
	int	y;

	if (gm->have_anime == 0)
		return ;
	gm->anime_size = 100 / gm->anime_dist;
	x = gm->anime_size + (int)gm->anime_angle;
	if (gm->anime_dist <= 32)
		y = 640 - gm->anime_dist * 10 - 2 * gm->anime_size;
	else if (gm->anime_dist > 32 && gm->anime_dist < 36)
		y = 640 - gm->anime_dist * 9 - 2 * gm->anime_size;
	else
		y = 320;
	put_sprite_to_image(gm, x, y);
	mlx_put_image_to_window(gm->win->mlx_ptr, gm->win->win_ptr, \
	gm->win->img, 0, 0);
}

static void	ch_1(t_dt *gm)
{
	gm->sprite_img.img = mlx_xpm_file_to_image(gm->win->mlx_ptr, \
	"./img/t1.xpm", &gm->sprite_img.x, &gm->sprite_img.y);
	gm->sprite_img.adr = mlx_get_data_addr(gm->sprite_img.img, \
	&gm->sprite_img.bpp, &gm->sprite_img.size_line, &gm->sprite_img.endian);
}

static void	ch2(t_dt *gm)
{
	gm->sprite_img.img = mlx_xpm_file_to_image(gm->win->mlx_ptr, \
	"./img/t2.xpm", &gm->sprite_img.x, &gm->sprite_img.y);
	gm->sprite_img.adr = mlx_get_data_addr(gm->sprite_img.img, \
	&gm->sprite_img.bpp, &gm->sprite_img.size_line, &gm->sprite_img.endian);
	gm->c.img = mlx_xpm_file_to_image(gm->win->mlx_ptr, "./img/t2.xpm", \
	&gm->anime_size, &gm->anime_size);
}

static void	ch3(t_dt *gm)
{
	gm->sprite_img.img = mlx_xpm_file_to_image(gm->win->mlx_ptr, \
	"./img/t3.xpm", &gm->sprite_img.x, &gm->sprite_img.y);
	gm->sprite_img.adr = mlx_get_data_addr(gm->sprite_img.img, \
	&gm->sprite_img.bpp, &gm->sprite_img.size_line, &gm->sprite_img.endian);
	gm->c.img = mlx_xpm_file_to_image(gm->win->mlx_ptr, "./img/t3.xpm", \
	&gm->anime_size, &gm->anime_size);
}

int	changer(t_dt *d)
{
	static int	i = 0;

	if (i == 0)
		ch_1(d);
	if (i == 30 || i == 90)
		ch2(d);
	if (i == 60)
		ch3(d);
	i++;
	if (i == 119)
		i = 0;
	risovalka(d);
	return (0);
}
