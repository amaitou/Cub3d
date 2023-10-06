/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 16:12:48 by amait-ou          #+#    #+#             */
/*   Updated: 2023/10/06 16:18:25 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../../superlib/superlib.h"
# include "../../mlx/include/MLX42/MLX42.h"
# include <math.h>
# include <fcntl.h>

# define WINDOW_HEIGHT 800
# define WINDOW_WIDTH 1500
# define TILE 10
# define MOVE_SPEED 1
# define RADIUS 1.75
# define FIELD_OF_VIEW 60
# define WALL_STRIP_WIDTH 12

// enum for texture directions
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

// struct for north direction
typedef struct s_north
{
	char			*texture;
	mlx_texture_t	*image;
	t_enums			direction;
}	t_north;

// struct for west direction
typedef struct s_west
{
	char			*texture;
	mlx_texture_t	*image;
	t_enums			direction;
}	t_west;

// struct for south direction
typedef struct s_south
{
	char			*texture;
	mlx_texture_t	*image;
	t_enums			direction;
}	t_south;

// struct for east direction
typedef struct s_east
{
	char			*texture;
	mlx_texture_t	*image;
	t_enums			direction;
}	t_east;

// struct for floor color
typedef struct s_color_f
{
	char	*surface;
	int		colors[3];
	char	*rgb;
	t_enums	type;
}	t_color_f;

// struct for ceiling color
typedef struct s_color_c
{
	char	*surface;
	int		colors[3];
	char	*rgb;
	t_enums	type;
}	t_color_c;

// struct for the elements before map
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

// struct for player
typedef struct s_player
{
	float	x;
	float	y;
	float	fov;
	float	radius;
	float	turn_direction;
	float	walk_direction;
	float	rotation_angle;
	float	move_speed;
	float	rotation_speed;
	char	direction;
}	t_player;

// struct for map that comes after elements (textures, colors)
typedef struct s_map
{
	char	**map;
	size_t	width;
	size_t	height;
	int		map_len;
}	t_map;

// struct for mlx
typedef struct s_mlx
{
	mlx_t		*mlx;
	mlx_image_t	*image;
}	t_mlx;

/*
	this struct used only when i need a variable \
	that i might use it as a temporary value holder
*/
typedef struct s_vars
{
	float			x_step;
	float			y_step;
	float			y_intercept;
	float			x_intercept;
	float			next_y;
	float			next_x;
	int				ray_facing_down;
	int				ray_facing_up;
	int				ray_facing_left;
	int				ray_facing_right;
	int				added_pixel;
	int				found_h_wall;
	int				found_v_wall;
	int				mouse_x;
	int				old_mouse_x;
	int				mouse_y;
	int				old_mouse_y;
	float			x_texures;
	float			y_textures;
	mlx_texture_t	*image;
}	t_vars;

/*
	struct for ray casting (each element of the struct \
	array would hold all of these members)
*/
typedef struct s_ray
{
	float	angle;
	float	v_distance;
	float	h_distance;
	float	h_wall_hit_x;
	float	h_wall_hit_y;
	float	v_wall_hit_x;
	float	v_wall_hit_y;
	float	wall_hit_x;
	float	wall_hit_y;
	float	distance;
	int		was_hit_vertical;
	float	wall_height;
	float	y_start;
	float	y_end;
	t_enums	direction;
	float	projection_plan;
}	t_rays;

/*
	this struct is used for the dda algorithm \
	that draws a line between to specific points
*/
typedef struct s_dda
{
	int		dx;
	int		dy;
	int		steps;
	float	xinc;
	float	yinc;
}	t_dda;

/*
	this struct holds all of the previous defined structs \
	+ some more vars that i might need in parsing or ray-casting operations
*/

typedef struct s_game
{
	t_elements		elements;
	t_player		player;
	t_mlx			mlx;
	t_map			map;
	t_dda			dda;
	t_vars			vars;
	t_rays			*rays;
	int				west;
	int				east;
	int				south;
	int				north;
	char			**all_items;
	char			*lines;
	char			*path;
	char			*temp;
	int				fd;
}	t_game;

// useful functions
char	**split2(char const *s);
int		__checker(t_game *game);
void	__banner(void);

// init members
void	init_all(t_game *game);

// cub3d
int		__run_game(t_game *game, int ac, char **ag);

// reader
int		__reader(t_game *game);
int		check_consecutive_new_lines(char *s);

// parser
int		__parser(t_game *game);
int		__rgb(t_game *game);
int		__map(t_game *game);
int		__walls(t_game *game);
int		check_directions(t_enums direction, char *s);
int		check_spaces(t_game *game);
void	skip_spaces(char **s);
int		check_textures(t_game *game);
int		check_map_and_elements(int parser_return_value);
void	assign_color(t_game *game, char **element);
void	assign_directions(t_game *game, char **element);
int		lines_count(t_game *game);

// displayer
void	__display_elements(t_game *game);
void	__display_map(t_game *game);
void	__display_rays(t_game *game);

// leaks
void	free_array(char **arr);
void	free_textures(t_game *game);

// game rendering
void	render_game(t_game *game);
void	draw_floor(t_game *game);
void	draw_ceiling(t_game *game);
void	clear_map(t_game *game);

// ray casting
void	cast_rays(t_game *game);
void	h_intersection(t_game *game, float ray_angle, int index);
void	v_intersection(t_game *game, float ray_angle, int index);
void	projection_plan(t_game *game);
int		get_rgba(int r, int g, int b, int a);
void	normalize_angle(float *angle);

// textures
int		load_textures(t_game *game);
int		get_color_of_texture(int x, int y, mlx_texture_t *image);
void	get_texture_x(t_game *game, int index, mlx_texture_t *image);
void	get_texture_y(t_game *game, int index, mlx_texture_t *image);
void	fix_fish_eye(t_game *game, int index);
void	calculate_wall_height(t_game *game, int index);
void	calculate_starting_point_of_the_wall(t_game *game, int index);
void	calculate_ending_point_of_the_wall(t_game *game, int index);
void	detect_texture(t_game *game, int index);

// player mouvements
void	move_up(t_game *game);
void	move_down(t_game *game);
void	move_right(t_game *game);
void	move_left(t_game *game);

// mlx hooks
void	check_keys(void *game);
void	mouse_hook(double curr_x, void *g);

// mlx exit
void	mlx_exit(t_game *game);

#endif
