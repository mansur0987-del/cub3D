/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armaxima <<armaxima@student.42.fr>>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 12:13:47 by armaxima          #+#    #+#             */
/*   Updated: 2022/06/19 23:58:49 by armaxima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define ERROR_ARGV "Error! Program must take as a first argument \
a scene description file with the .cub extension.\n"
# define ERROR_READ "Error! Cannot read from file.\n"
# define ERROR_FILE "Error! Badly file.\n"
# define WIN_Y 1280
# define WIN_X 720
# define DIFF_YX 0.5625
# define PI 3.14159265
# define DPI 6.2831853
# define POLPI 1.5707963

# include "../libft/libft.h"
# include <fcntl.h>
# include <mlx.h>
# include <math.h>
# include <stdio.h>

typedef struct s_img
{
	void	*img;
	char	*path;
	int		col;
	int		x;
	int		y;
	char	*adr;
	int		bpp;
	int		size_line;
	int		endian;
}				t_img;

typedef struct s_pers
{
	int		col;
	int		x;
	int		y;
	int		stx;
	int		sty;
	float	sax;
	float	say;
	double	rx;
	double	ry;
	char	direct;
	float	ang;
	double	ang_tmp;
}				t_pers;

typedef struct s_win
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img;
	char	*adr;
	int		bpp;
	int		size_line;
	int		endian;
}				t_win;

typedef struct s_wall
{
	int		ix;
	int		iy;
	double	dx;
	double	dy;
	double	tmp;
	double	stena;
}				t_wall;

typedef struct s_anm
{
	void	*img;
	char	*relative_path;
	int		img_width;
	int		img_height;
}				t_anm;

typedef struct s_dt
{
	int		step;
	int		xp;
	int		yp;
	int		err;
	char	*file;
	int		mouse_x;
	int		mouse_y;
	float	anime_angle;
	int		anime_dist;
	int		have_anime;
	int		anime_size;

	t_anm	c;
	t_img	sprite_img;
	t_anm	v;
	t_img	*nw;
	t_img	*sw;
	t_img	*ww;
	t_img	*ew;
	t_img	*up;
	t_img	*pol;
	t_img	*door;
	t_win	*win;
	t_pers	*pers;
	char	**data;
	t_wall	wall;
	int		is_door;
}				t_dt;

int		ft_check(int argc, char **argv, t_dt *game);
int		ft_check_file(t_dt *game);
int		ft_skip_sp(char *str, int i);
int		ft_skip_text(char *str, int i);
int		ft_check_map(char **map, t_img *up, t_img *down);
int		ft_game(t_dt *game);
int		ft_init_win(t_dt *game);
int		ft_init_img(t_dt *game);
int		ft_init_pers(t_dt *game);
int		ft_draw(t_dt *game);
void	ft_init_direct_pers(t_dt *gm);
void	ft_paint_small_map(t_dt *gm);
void	ft_paint_up_pol(t_dt *gm);
void	ft_min_player_put(t_dt *game, int x, int y, int col);
void	ft_wall_paint(t_dt *gm);
void	ft_put_mlx_pixel(t_dt *gm, int x, int y, int col);
void	ft_ray(t_dt *gm);
int		ft_keys(int key, t_dt *game);
int		ft_exit(t_dt *game);
void	ft_left(t_dt *gm);
void	ft_right(t_dt *gm);
void	ft_up(t_dt *gm);
void	ft_down(t_dt *gm);
int		ft_draw_wall2(t_dt *gm, int y);
t_img	*ft_get_door(int *error);
char	*ft_get_local(char *str, int *i, int g);
void	ft_open_door(t_dt *gm);
int		changer(t_dt *d);
void	ft_search_anime(t_dt *gm);
void	put_sprite_to_image(t_dt *gm, int i, int j);
int		ft_double_image(t_dt *gm, char *str);

#endif
