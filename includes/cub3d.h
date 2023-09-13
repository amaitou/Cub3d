/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 12:55:08 by amait-ou          #+#    #+#             */
/*   Updated: 2023/09/13 21:16:56 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../superlib/superlib.h"
# include "../mlx/include/MLX42/MLX42.h"
# include <math.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>

# define TILE 30

typedef enum e_enums
{
	_NORTH,
	_WEST,
	_SOUTH,
	_EAST,
	_COLOR_F,
	_COLOR_C,
	_NONE
}	t_enums;

typedef struct s_north
{
	char			*texture;
	t_enums			direction;
}	t_north;

typedef struct s_west
{
	char			*texture;
	t_enums			direction;
}	t_west;

typedef struct s_south
{
	char			*texture;
	t_enums			direction;
}	t_south;

typedef struct s_east
{
	char			*texture;
	t_enums			direction;
}	t_east;

typedef struct s_color_f
{
	char	*surface;
	char	*rgb;
	t_enums	type;
}	t_color_f;

typedef struct s_color_c
{
	char	*surface;
	char	*rgb;
	t_enums	type;
}	t_color_c;

typedef struct s_elements
{
	int			counter;
	t_north		north;
	t_east		east;
	t_south		south;
	t_west		west;
	t_color_f	floor_c;
	t_color_c	ceiling_c;
}	t_elements;

typedef struct s_player
{
	float	x;
	float	y;
	float	radius;
	int		turn_direction;
	int		walk_direction;
	float	rotation_angle;
	float	move_speed;
	float	rotation_speed;
}	t_player;

typedef struct s_dda
{
	int		dy;
	int		dx;
	int		steps;
	float	xinc;
	float	yinc;
}	t_dda;

typedef struct s_map
{
	char	**map;
	size_t	width;
	size_t	height;
	int		map_len;
}	t_map;

typedef struct s_mlx
{
	mlx_t		*mlx;
	mlx_image_t	*window;
}	t_mlx;

typedef struct s_game
{
	t_elements		elements;
	t_player		player;
	t_mlx			mlx;
	t_map			map;
	t_dda			dda;
	int				west;
	int				east;
	int				south;
	int				north;
	char			**all_items;
	char			*lines;
	char			*path;
	int				fd;
}	t_game;

// init members
void	init_directions(t_game *game);
void	init_map(t_game *game);
void	init_elements(t_game *game);
void	init_player(t_game *game);
void	init_all(t_game *game);

// cub3d
int		get_rgba(int r, int g, int b, int a);
void	mlx(t_game *game);

// reader
int		__reader(t_game *game);

// parser
void	assign_color(t_game *game, char **element);
void	assign_directions(t_game *game, char **element);
int		lines_count(t_game *game);
int		__parser(t_game *game);

// displayer
void	__display_items(t_game *game);
void	__display_elements(t_game *game);
void	__display_map(t_game *game);

// leaks
void	free_array(char **arr);

// error
int		check_reader(t_game *game);
int		check_consecutive_new_lines(char *s);
int		check_parser(t_game *game);
int		check_elements(t_game *game);
int		check_map(t_game *game);
int		check_map_helper(t_game *game, int i, int j);
int		starts_with_one(char *s);
int		ends_with_one(char *s);
int		check_walls(t_game *game);
int		map_closed(t_game *game);
int		check_rgb(t_game *game);
int		__checker(t_game *game);
void	error_helper(t_game *game, char d, int x, int y);

// mini map
void	draw_mini_map(t_game *game);

// player mouvements
void	move_up(t_game *game);
void	move_down(t_game *game);
void	move_right(t_game *game);
void	move_left(t_game *game);
void	dda(t_game *game, int x, int y);

// mlx hooks
void	check_keys(void *game);

#endif
