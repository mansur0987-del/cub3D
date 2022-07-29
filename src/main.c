/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armaxima <<armaxima@student.42.fr>>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 12:13:29 by armaxima          #+#    #+#             */
/*   Updated: 2022/06/17 18:10:21 by armaxima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_dt	*ft_init_game(void)
{
	t_dt	*game;

	game = malloc(sizeof(t_dt));
	if (game == NULL)
	{
		ft_putstr_fd("Error! missing memory!", 2);
		return (NULL);
	}
	game->anime_size = 4;
	game->err = 0;
	game->file = NULL;
	game->nw = NULL;
	game->sw = NULL;
	game->ww = NULL;
	game->ew = NULL;
	game->pol = NULL;
	game->up = NULL;
	game->door = NULL;
	game->pers = NULL;
	return (game);
}

int	main(int argc, char **argv)
{
	t_dt	*game;

	game = ft_init_game();
	if (game == NULL || ft_check(argc, argv, game))
		return (1);
	if (ft_game(game))
		return (1);
	return (0);
}
