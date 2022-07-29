/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armaxima <<armaxima@student.42.fr>>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 14:36:04 by armaxima          #+#    #+#             */
/*   Updated: 2022/06/19 07:27:39 by kmarg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_exit(t_dt *game)
{
	ft_putstr_fd("Exit!\n", 1);
	exit(game->err);
}

void	ft_search_anime(t_dt *gm)
{
	double	sb;
	int		i;

	gm->anime_angle = 0;
	sb = gm->pers->ang + M_PI / 4;
	while (sb > (gm->pers->ang - M_PI / 4))
	{
		i = 1;
		while (gm->data[(int)(gm->pers->x + (gm->pers->sax - i * cos(sb)) / \
	10)][(int)(gm->pers->y + ((gm->pers->say - i * sin(sb)) / 10))] != '1')
		{
			if (gm->data[(int)(gm->pers->x + (gm->pers->sax - i * cos(sb)) / \
	10)][(int)(gm->pers->y + ((gm->pers->say - i * sin(sb)) / 10))] == 'Z')
			{
				gm->anime_dist = i;
				gm->have_anime = 1;
				return ;
			}
			i++;
		}
		gm->anime_angle++;
		sb = sb - 0.001228;
	}	
	gm->have_anime = 0;
}

void	ft_ray(t_dt *gm)
{
	double	sb;
	int		n;
	int		i;

	sb = gm->pers->ang - M_PI / 4;
	n = 0;
	ft_paint_small_map(gm);
	while (sb < (gm->pers->ang + M_PI / 4))
	{
		i = 1;
		while (gm->data[(int)(gm->pers->x + (gm->pers->sax - i * cos(sb)) / \
	10)][(int)(gm->pers->y + ((gm->pers->say - i * sin(sb)) / 10))] == '0' || \
	gm->data[(int)(gm->pers->x + (gm->pers->sax - i * cos(sb)) / \
	10)][(int)(gm->pers->y + ((gm->pers->say - i * sin(sb)) / 10))] == 'F')
		{
			ft_put_mlx_pixel(gm, \
	(int)(gm->pers->x * 10 + (int)gm->pers->sax - i * cos(sb)), \
	(int)(gm->pers->y * 10 + (int)gm->pers->say - i * sin(sb)), 0xdd0000);
			i++;
		}
		sb = sb + 0.001228;
	}
	return ;
}

int	ft_ms(int key, int x, int y, t_dt *gm)
{
	if (key == 1)
		gm->pers->ang = gm->pers->ang + M_PI / 36;
	if (key == 2)
		gm->pers->ang = gm->pers->ang - M_PI / 36;
	if (key == 4)
		ft_down(gm);
	if (key == 5)
		ft_up(gm);
	if (key == 3 && x > gm->mouse_x)
	{
		ft_right(gm);
		gm->mouse_x = x;
	}
	if (key == 3 && x < gm->mouse_x)
	{
		ft_left(gm);
		gm->mouse_x = x;
	}
	y = y + 0;
	ft_draw(gm);
	return (0);
}

int	ft_game(t_dt *gm)
{
	if (ft_init_win(gm) || ft_init_img(gm) || ft_init_pers(gm))
		return (1);
	ft_init_direct_pers(gm);
	if (ft_draw(gm))
	{
		ft_putstr_fd("Error! Window not visualization!", 1);
		return (1);
	}
	gm->mouse_x = 0;
	gm->mouse_y = 0;
	mlx_hook(gm->win->win_ptr, 17, 1L << 17, ft_exit, gm);
	mlx_hook(gm->win->win_ptr, 4, 1L << 0, ft_ms, gm);
	mlx_hook(gm->win->win_ptr, 2, 1L << 0, ft_keys, gm);
	mlx_loop_hook(gm->win->mlx_ptr, changer, gm);
	mlx_do_sync(gm->win->mlx_ptr);
	mlx_loop(gm->win->mlx_ptr);
	return (0);
}
