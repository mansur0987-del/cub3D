/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armaxima <<armaxima@student.42.fr>>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 17:46:43 by armaxima          #+#    #+#             */
/*   Updated: 2022/06/19 07:34:49 by kmarg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_init_win(t_dt *game)
{
	game->win = NULL;
	game->win = malloc(sizeof(t_win));
	if (game->win == NULL)
		return (1);
	game->win->mlx_ptr = mlx_init();
	game->win->win_ptr = mlx_new_window(game->win->mlx_ptr, WIN_Y, WIN_X, \
	"cub3D");
	game->win->img = mlx_new_image(game->win->mlx_ptr, WIN_Y, WIN_X);
	game->win->bpp = 32;
	game->win->size_line = 0;
	game->win->endian = 0;
	game->win->adr = mlx_get_data_addr(game->win->img, &game->win->bpp, \
	&game->win->size_line, &game->win->endian);
	game->sprite_img.img = mlx_xpm_file_to_image(game->win->mlx_ptr, \
	"./img/t2.xpm", &game->sprite_img.x, &game->sprite_img.y);
	game->sprite_img.adr = mlx_get_data_addr(game->sprite_img.img, \
	&game->sprite_img.bpp, &game->sprite_img.size_line, \
	&game->sprite_img.endian);
	return (0);
}

int	ft_init_img(t_dt *game)
{
	game->nw->img = mlx_xpm_file_to_image(game->win->mlx_ptr, game->nw->path, \
	&game->nw->x, &game->nw->y);
	game->nw->adr = mlx_get_data_addr(game->nw->img, &game->nw->bpp, \
	&game->nw->size_line, &game->nw->endian);
	game->sw->img = mlx_xpm_file_to_image(game->win->mlx_ptr, game->sw->path, \
	&game->sw->x, &game->sw->y);
	game->sw->adr = mlx_get_data_addr(game->sw->img, &game->sw->bpp, \
	&game->sw->size_line, &game->sw->endian);
	game->ww->img = mlx_xpm_file_to_image(game->win->mlx_ptr, game->ww->path, \
	&game->ww->x, &game->ww->y);
	game->ww->adr = mlx_get_data_addr(game->ww->img, &game->ww->bpp, \
	&game->ww->size_line, &game->ww->endian);
	game->ew->img = mlx_xpm_file_to_image(game->win->mlx_ptr, game->ew->path, \
	&game->ew->x, &game->ew->y);
	game->ew->adr = mlx_get_data_addr(game->ew->img, &game->ew->bpp, \
	&game->ew->size_line, &game->ew->endian);
	game->door->img = mlx_xpm_file_to_image(game->win->mlx_ptr, \
	game->door->path, &game->door->x, &game->door->y);
	game->door->adr = mlx_get_data_addr(game->door->img, &game->door->bpp, \
	&game->door->size_line, &game->door->endian);
	return (0);
}

int	ft_init_pers(t_dt *game)
{
	int	x;
	int	y;

	x = 0;
	game->pers = malloc(sizeof(t_pers));
	if (game->pers == NULL)
		return (1);
	game->pers->col = 0x00FF00FF;
	while (game->data[x])
	{
		y = 0;
		while (game->data[x][y] && (game->data[x][y] == '1' || \
		game->data[x][y] == '0' || game->data[x][y] == ' ' || \
		game->data[x][y] == 'Z' || game->data[x][y] == 'D'))
			y++;
		if (game->data[x][y])
		{
			game->pers->x = (double) x;
			game->pers->y = (double) y;
			game->pers->direct = game->data[x][y];
			return (0);
		}
		x++;
	}
	return (1);
}

void	ft_init_direct_pers(t_dt *gm)
{
	if (gm->pers->direct == 'N')
		gm->pers->ang = 0;
	else if (gm->pers->direct == 'S')
		gm->pers->ang = PI;
	else if (gm->pers->direct == 'W')
		gm->pers->ang = PI / 2;
	else if (gm->pers->direct == 'E')
		gm->pers->ang = PI / 2 * 3;
	gm->data[gm->pers->x][gm->pers->y] = '0';
}

t_img	*ft_get_door(int *error)
{
	t_img	*new;

	new = malloc(sizeof(t_img));
	if (new == NULL)
		return (NULL);
	new->adr = NULL;
	new->img = NULL;
	new->bpp = 0;
	new->endian = 0;
	new->size_line = 0;
	new->x = 0;
	new->y = 0;
	new->col = 0;
	new->path = ft_get_local(" ./img/walls/door.xpm ", &new->x, 0);
	new->x = 0;
	if (new->path != NULL)
		return (new);
	*error = 1;
	free(new);
	return (NULL);
}
