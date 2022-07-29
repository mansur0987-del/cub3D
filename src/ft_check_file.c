/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armaxima <<armaxima@student.42.fr>>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 18:28:21 by armaxima          #+#    #+#             */
/*   Updated: 2022/06/19 23:58:27 by armaxima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*ft_get_local(char *str, int *i, int g)
{
	int		start;
	char	*string;

	*i = *i + g;
	if (str[*i] != ' ' && str[*i] != '\t' && str[*i] != '\n')
		return (NULL);
	*i = ft_skip_sp(str, *i);
	start = *i;
	*i = ft_skip_text(str, *i);
	if (str[start] != '.' || !(str[*i]))
		return (NULL);
	string = ft_substr(str, start, *i - start);
	if (string == NULL)
		return (NULL);
	start = open(string, O_RDONLY);
	if (start != -1)
	{
		close(start);
		return (string);
	}
	free(string);
	return (NULL);
}

char	*ft_get_color(char *str, int *i, int g)
{
	int		start;
	char	*string;

	*i = *i + g;
	if (str[*i] != ' ' && str[*i] != '\t' && str[*i] != '\n')
		return (NULL);
	*i = ft_skip_sp(str, *i);
	start = *i;
	*i = ft_skip_text(str, *i);
	if (!(str[*i]))
		return (NULL);
	string = ft_substr(str, start, *i - start);
	if (string == NULL)
		return (NULL);
	return (string);
}

t_img	*ft_get_image1(char *str, int *i, int g, int *error)
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
	if (str[*i] == 'F' || str[*i] == 'C')
		new->path = ft_get_color(str, i, g);
	else
		new->path = ft_get_local(str, i, g);
	if (new->path != NULL)
		return (new);
	*error = 1;
	free(new);
	return (NULL);
}

int	ft_get_image(t_dt *game, int *i)
{
	*i = ft_skip_sp(game->file, *i);
	if (ft_double_image(game, game->file + *i))
		return (1);
	if (!(ft_strncmp(game->file + *i, "NO ", 3)))
		game->nw = ft_get_image1(game->file, i, 2, &(game->err));
	if (!(ft_strncmp(game->file + *i, "SO ", 3)))
		game->sw = ft_get_image1(game->file, i, 2, &(game->err));
	if (!(ft_strncmp(game->file + *i, "WE ", 3)))
		game->ww = ft_get_image1(game->file, i, 2, &(game->err));
	if (!(ft_strncmp(game->file + *i, "EA ", 3)))
		game->ew = ft_get_image1(game->file, i, 2, &(game->err));
	if (!(ft_strncmp(game->file + *i, "F ", 2)))
		game->pol = ft_get_image1(game->file, i, 1, &(game->err));
	if (!(ft_strncmp(game->file + *i, "C ", 2)))
		game->up = ft_get_image1(game->file, i, 1, &(game->err));
	if (game->err)
		return (1);
	return (0);
}

int	ft_check_file(t_dt *gm)
{
	int	i;

	i = 0;
	while (gm->file[i])
	{
		if (ft_get_image(gm, &i))
			return (1);
		if (gm->nw != NULL && gm->sw != NULL && gm->ww != NULL \
		&& gm->ew != NULL && gm->up != NULL && gm->pol != NULL)
		{
			gm->data = ft_split(gm->file + i, '\n');
			break ;
		}
		i++;
	}
	free(gm->file);
	if (gm->nw == NULL || gm->sw == NULL || gm->ww == NULL \
		|| gm->ew == NULL || gm->up == NULL || gm->pol == NULL \
		|| ft_check_map(gm->data, gm->up, gm->pol))
		return (1);
	return (0);
}
