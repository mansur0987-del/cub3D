/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armaxima <<armaxima@student.42.fr>>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 14:06:54 by armaxima          #+#    #+#             */
/*   Updated: 2022/06/19 23:50:41 by armaxima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_check_name_map(char *argv)
{
	int	len;

	len = ft_strlen(argv);
	if (len <= 4 || argv[len - 4] != '.' || argv[len - 3] != 'c' || \
		argv[len - 2] != 'u' || argv[len - 1] != 'b')
		return (1);
	return (0);
}

char	*ft_read(int fd)
{
	char	*tmp;
	char	*tmp_2;
	char	*tmp_3;

	tmp = ft_strdup("");
	while (tmp != NULL)
	{
		tmp_2 = get_next_line(fd);
		if (tmp_2 == NULL)
			return (tmp);
		tmp_3 = ft_strjoin(tmp, tmp_2);
		free(tmp_2);
		free(tmp);
		tmp = ft_strdup(tmp_3);
		free(tmp_3);
	}
	return (tmp);
}

int	ft_open(char *argv, char **file)
{
	int	fd;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
		return (1);
	if (read(fd, NULL, 0) == -1)
	{
		close(fd);
		return (1);
	}
	*file = ft_read(fd);
	close(fd);
	if (file == NULL)
		return (1);
	return (0);
}

int	ft_check(int argc, char **argv, t_dt *game)
{
	if (argc != 2 || ft_check_name_map(argv[1]))
	{
		ft_putstr_fd(ERROR_ARGV, 2);
		exit(1);
	}
	if (ft_open(argv[1], &(game->file)))
	{
		ft_putstr_fd(ERROR_READ, 2);
		exit(1);
	}
	if (ft_check_file(game))
	{
		ft_putstr_fd(ERROR_FILE, 2);
		exit(1);
	}
	game->door = ft_get_door(&(game->err));
	return (0);
}
