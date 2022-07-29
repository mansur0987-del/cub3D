/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armaxima <<armaxima@student.42.fr>>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 17:43:07 by armaxima          #+#    #+#             */
/*   Updated: 2022/06/19 23:58:40 by armaxima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_skip_sp(char *str, int i)
{
	while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
		i++;
	return (i);
}

int	ft_skip_text(char *str, int i)
{
	while (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
		i++;
	return (i);
}

void	ft_put_mlx_pixel(t_dt *gm, int x, int y, int col)
{
	char	*tmp_adr;

	tmp_adr = gm->win->adr + (x * gm->win->size_line) + \
	(y * (gm->win->bpp / 8));
	*(int *)tmp_adr = col;
}

int	ft_draw_wall2(t_dt *gm, int y)
{
	if (gm->is_door == 1)
		ft_put_mlx_pixel(gm, (int)(WIN_X / 2 - gm->wall.stena), y,
			((int*)gm->door->adr)[gm->wall.iy]);
	else if ((gm->wall.dy < 0.02 || gm->wall.dy > 0.98)
		&& (gm->wall.dx > 0.98 || gm->wall.dx < 0.02))
		return (0);
	else if (gm->wall.dx > 0.98)
		ft_put_mlx_pixel(gm, (int)(WIN_X / 2 - gm->wall.stena), y,
			((int*)gm->sw->adr)[gm->wall.iy]);
	else if (gm->wall.dy > 0.98)
		ft_put_mlx_pixel(gm, (int)(WIN_X / 2 - gm->wall.stena), y,
			((int*)gm->nw->adr)[gm->wall.ix]);
	else if (gm->wall.dx < 0.02)
		ft_put_mlx_pixel(gm, (int)(WIN_X / 2 - gm->wall.stena), y,
			((int*)gm->ew->adr)[gm->wall.iy]);
	else if (gm->wall.dy < 0.02)
		ft_put_mlx_pixel(gm, (int)(WIN_X / 2 - gm->wall.stena), y,
			((int*)gm->ww->adr)[gm->wall.ix]);
	gm->wall.stena--;
	return (1);
}

int	ft_double_image(t_dt *gm, char *str)
{
	if (!(ft_strncmp(str, "NO ", 3)) && gm->nw != NULL)
		return (1);
	if (!(ft_strncmp(str, "SO ", 3)) && gm->sw != NULL)
		return (1);
	if (!(ft_strncmp(str, "WE ", 3)) && gm->ww != NULL)
		return (1);
	if (!(ft_strncmp(str, "EA ", 3)) && gm->ew != NULL)
		return (1);
	if (!(ft_strncmp(str, "F ", 2)) && gm->pol != NULL)
		return (1);
	if (!(ft_strncmp(str, "C ", 2)) && gm->up != NULL)
		return (1);
	return (0);
}
