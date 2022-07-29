/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_door.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armaxima <<armaxima@student.42.fr>>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 19:23:40 by armaxima          #+#    #+#             */
/*   Updated: 2022/06/19 07:36:25 by kmarg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_open_door(t_dt *gm)
{
	if (gm->data[(int)(gm->pers->x + (gm->pers->sax - \
		cos(gm->pers->ang)) / 10)][(int)(gm->pers->y + \
	((gm->pers->say - sin(gm->pers->ang)) / 10))] == 'D')
	{
		gm->data[(int)(gm->pers->x + (gm->pers->sax - \
		cos(gm->pers->ang)) / 10)][(int)(gm->pers->y + \
	((gm->pers->say - sin(gm->pers->ang)) / 10))] = 'F';
	}
	else if (gm->data[(int)(gm->pers->x + (gm->pers->sax - \
		cos(gm->pers->ang)) / 10)][(int)(gm->pers->y + \
	((gm->pers->say - sin(gm->pers->ang)) / 10))] == 'F')
	{
		gm->data[(int)(gm->pers->x + (gm->pers->sax - \
		cos(gm->pers->ang)) / 10)][(int)(gm->pers->y + \
	((gm->pers->say - sin(gm->pers->ang)) / 10))] = 'D';
	}
}

static void	pixel_put(t_win *img, int x, int y, unsigned int color)
{
	char	*dst;

	dst = img->adr + (y * img->size_line + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

static unsigned int	get_pixel(t_img *img, int x, int y)
{
	return ((unsigned int)(*(unsigned int *)(img->adr + \
	(y * img->size_line + x * (img->bpp / 8)))));
}

void	put_sprite_to_image(t_dt *gm, int i, int j)
{
	int				x;
	int				y;
	unsigned int	o;

	y = 0;
	while (y < 64 * gm->anime_size)
	{
		x = 0;
		while (x < 64 * gm->anime_size)
		{
			o = get_pixel(&gm->sprite_img, x / gm->anime_size, \
			y / gm->anime_size);
			if (o != 4278190080)
				pixel_put(gm->win, x + i, y + j, o);
			x++;
		}
		y++;
	}
}
