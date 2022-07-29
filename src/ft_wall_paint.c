/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wall_paint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armaxima <<armaxima@student.42.fr>>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 16:36:21 by armaxima          #+#    #+#             */
/*   Updated: 2022/06/17 19:30:00 by armaxima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_draw_wall(t_dt *gm, int y, double start)
{
	gm->wall.stena = WIN_X / 10 / (sqrt(powf(gm->pers->rx
					- ((double)gm->pers->x + gm->pers->sax * 0.1), 2) \
					+ powf(gm->pers->ry - ((double)gm->pers->y \
					+ gm->pers->say * 0.1), 2)));
	gm->wall.stena /= sin(gm->pers->ang_tmp - start);
	gm->wall.dx = modf(gm->pers->rx, &gm->wall.tmp);
	gm->wall.dy = modf(gm->pers->ry, &gm->wall.tmp);
	gm->wall.tmp = gm->wall.stena;
	if (gm->wall.stena > WIN_X / 2)
		gm->wall.stena = WIN_X / 2;
	while (gm->wall.stena > -gm->wall.tmp
		&& gm->wall.stena > -WIN_X / 2)
	{
		gm->wall.ix = ((int)((gm->wall.tmp - gm->wall.stena) \
			/ gm->wall.tmp * 64) / 2) * 64 \
			+ (int)(gm->wall.dx * 64);
		gm->wall.iy = ((int)((gm->wall.tmp - gm->wall.stena) \
			/ gm->wall.tmp * 64) / 2) * 64 \
			+ (int)(gm->wall.dy * 64);
		if (!ft_draw_wall2(gm, y))
			return (0);
	}
	return (1);
}

void	ft_distance(t_dt *gm, double start)
{
	gm->is_door = 0;
	gm->pers->ry = ((double)gm->pers->y + gm->pers->say * 0.1);
	gm->pers->rx = ((double)gm->pers->x + gm->pers->sax * 0.1);
	while (gm->data[(int)gm->pers->rx][(int)gm->pers->ry] == '0' || \
	gm->data[(int)gm->pers->rx][(int)gm->pers->ry] == 'Z' || \
	gm->data[(int)gm->pers->rx][(int)gm->pers->ry] == 'T' || \
	gm->data[(int)gm->pers->rx][(int)gm->pers->ry] == 'F')
	{
		gm->pers->rx = gm->pers->rx + cos(start) / 64 * 0.1;
		gm->pers->ry = gm->pers->ry + sin(start) / 64 * 0.1;
	}
	if (gm->data[(int)gm->pers->rx][(int)gm->pers->ry] == 'D')
		gm->is_door = 1;
}

void	ft_wall_paint3(t_dt *gm, int y)
{
	double	start;
	double	end;

	start = gm->pers->ang_tmp - POLPI;
	end = start - POLPI / 2;
	while (start >= end)
	{
		ft_distance(gm, start);
		if (!ft_draw_wall(gm, y, start))
		{
			y--;
			end -= POLPI / (WIN_Y);
		}
		y++;
		start -= POLPI / (WIN_Y);
	}
}

void	ft_wall_paint2(t_dt *gm, int y)
{
	double	start;
	double	end;

	start = gm->pers->ang_tmp - POLPI;
	end = start + POLPI / 2;
	while (start <= end)
	{
		ft_distance(gm, start);
		if (!ft_draw_wall(gm, y, start))
		{
			y++;
			end += POLPI / WIN_Y;
		}
		y--;
		start += POLPI / WIN_Y;
	}
}

void	ft_wall_paint(t_dt *gm)
{
	gm->is_door = 0;
	if (gm->pers->ang < 0 && gm->pers->ang < -DPI)
		gm->pers->ang += DPI;
	if (gm->pers->ang > 0 && gm->pers->ang > DPI)
		gm->pers->ang -= DPI;
	gm->pers->ang_tmp = gm->pers->ang - POLPI;
	ft_wall_paint3(gm, WIN_Y / 2);
	ft_wall_paint2(gm, WIN_Y / 2);
}
