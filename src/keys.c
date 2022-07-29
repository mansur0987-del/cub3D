/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armaxima <<armaxima@student.42.fr>>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 00:59:59 by kmarg             #+#    #+#             */
/*   Updated: 2022/06/17 19:35:21 by armaxima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_left(t_dt *gm)
{
	if (gm->data[(int)(gm->pers->x + (gm->pers->sax - cos(gm->pers->ang + \
	M_PI / 2)) / 10)][(int)(gm->pers->y + ((gm->pers->say - \
	sin(gm->pers->ang + M_PI / 2)) / 10))] == '1' || \
	gm->data[(int)(gm->pers->x + (gm->pers->sax - cos(gm->pers->ang + \
	M_PI / 2)) / 10)][(int)(gm->pers->y + ((gm->pers->say - \
	sin(gm->pers->ang + M_PI / 2)) / 10))] == 'D')
		return ;
	ft_put_mlx_pixel(gm, \
	(gm->pers->x * 10 + (int)gm->pers->sax), \
	(gm->pers->y * 10 + (int)gm->pers->say), gm->up->col);
	gm->pers->sax = gm->pers->sax - cos(gm->pers->ang + M_PI / 2);
	gm->pers->say = gm->pers->say - sin(gm->pers->ang + M_PI / 2);
	ft_put_mlx_pixel(gm, \
	(gm->pers->x * 10 + (int)gm->pers->sax), \
	(gm->pers->y * 10 + (int)gm->pers->say), 0xdd0000);
}

void	ft_right(t_dt *gm)
{
	if (gm->data[(int)(gm->pers->x + (gm->pers->sax + \
	cos(gm->pers->ang + M_PI / 2)) / 10)][(int)(gm->pers->y + \
	((gm->pers->say + sin(gm->pers->ang + M_PI / 2)) / 10))] == '1' || \
	gm->data[(int)(gm->pers->x + (gm->pers->sax + \
	cos(gm->pers->ang + M_PI / 2)) / 10)][(int)(gm->pers->y + \
	((gm->pers->say + sin(gm->pers->ang + M_PI / 2)) / 10))] == 'D')
		return ;
	ft_put_mlx_pixel(gm, \
	(gm->pers->x * 10 + (int)gm->pers->sax), \
	(gm->pers->y * 10 + (int)gm->pers->say), gm->up->col);
	gm->pers->sax = gm->pers->sax + cos(gm->pers->ang + M_PI / 2);
	gm->pers->say = gm->pers->say + sin(gm->pers->ang + M_PI / 2);
	ft_put_mlx_pixel(gm, (gm->pers->x * 10 + (int)gm->pers->sax),
		(gm->pers->y * 10 + (int)gm->pers->say), 0xdd0000);
}

void	ft_up(t_dt *gm)
{
	if (gm->data[(int)(gm->pers->x + (gm->pers->sax - \
		cos(gm->pers->ang)) / 10)][(int)(gm->pers->y + \
	((gm->pers->say - sin(gm->pers->ang)) / 10))] == '1' || \
	gm->data[(int)(gm->pers->x + (gm->pers->sax - \
		cos(gm->pers->ang)) / 10)][(int)(gm->pers->y + \
	((gm->pers->say - sin(gm->pers->ang)) / 10))] == 'D')
		return ;
	ft_put_mlx_pixel(gm, \
	(gm->pers->x * 10 + (int)gm->pers->sax), \
	(gm->pers->y * 10 + (int)gm->pers->say), gm->up->col);
	gm->pers->sax = gm->pers->sax - cos(gm->pers->ang);
	gm->pers->say = gm->pers->say - sin(gm->pers->ang);
	ft_put_mlx_pixel(gm, \
	(gm->pers->x * 10 + (int)gm->pers->sax), \
	(gm->pers->y * 10 + (int)gm->pers->say), 0xdd0000);
}

void	ft_down(t_dt *gm)
{
	if (gm->data[(int)(gm->pers->x + (gm->pers->sax + \
	cos(gm->pers->ang)) / 10)][(int)(gm->pers->y + ((gm->pers->say + \
	sin(gm->pers->ang)) / 10))] == '1' || \
	gm->data[(int)(gm->pers->x + (gm->pers->sax + \
	cos(gm->pers->ang)) / 10)][(int)(gm->pers->y + ((gm->pers->say + \
	sin(gm->pers->ang)) / 10))] == 'D')
		return ;
	ft_put_mlx_pixel(gm, \
	(gm->pers->x * 10 + (int)gm->pers->sax), \
	(gm->pers->y * 10 + (int)gm->pers->say), gm->up->col);
	gm->pers->sax = gm->pers->sax + cos(gm->pers->ang);
	gm->pers->say = gm->pers->say + sin(gm->pers->ang);
	ft_put_mlx_pixel(gm, \
	(gm->pers->x * 10 + (int)gm->pers->sax), \
	(gm->pers->y * 10 + (int)gm->pers->say), 0xdd0000);
}

int	ft_keys(int key, t_dt *game)
{
	if (key == 53)
	{
		mlx_destroy_window(game->win->mlx_ptr, game->win->win_ptr);
		ft_exit(game);
	}
	if (key == 0)
		ft_left(game);
	if (key == 2)
		ft_right(game);
	if (key == 123)
		game->pers->ang = game->pers->ang + M_PI / 36;
	if (key == 1)
		ft_down(game);
	if (key == 124)
		game->pers->ang = game->pers->ang - M_PI / 36;
	if (key == 13)
		ft_up(game);
	if (key == 14)
		ft_open_door(game);
	ft_draw(game);
	return (0);
}
