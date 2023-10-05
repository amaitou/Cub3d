/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_plan.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 15:54:57 by amait-ou          #+#    #+#             */
/*   Updated: 2023/10/05 02:46:12 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	draw_wall(t_game *game, int index, int x, int y)
{
	// if (game->rays[index].direction == _NORTH)
	// 	mlx_put_pixel(game->mlx.image, index, game->rays[index].y_start,
	// 		get_rgba(255, 0, 0, 255));
	// else if (game->rays[index].direction == _SOUTH)
	// 	mlx_put_pixel(game->mlx.image, index, game->rays[index].y_start,
	// 		get_rgba(0, 153, 0, 255));
	// else if (game->rays[index].direction == _EAST)
	// 	mlx_put_pixel(game->mlx.image, index, game->rays[index].y_start,
	// 		get_rgba(255, 255, 0, 255));
	// else if (game->rays[index].direction == _WEST)
	// 	mlx_put_pixel(game->mlx.image, index, game->rays[index].y_start,
	// 		get_rgba(102, 51, 0, 255));
	mlx_put_pixel(game->mlx.image, index, game->rays[index].y_start, get_color_of_texture(x, y, game->elements.north.image));
}
void	projection_plan(t_game *game)
{
	size_t	i;

	i = -1;
	while (++i < WINDOW_WIDTH)
	{
		game->rays[i].distance *= cos(game->player.rotation_angle
				- game->rays[i].angle);
		game->rays[i].wall_height = (WINDOW_HEIGHT
				/ game->rays[i].distance) * WALL_STRIP_WIDTH;
		if (game->rays[i].wall_height > WINDOW_HEIGHT)
			game->rays[i].wall_height = WINDOW_HEIGHT;
		game->rays[i].y_start = (WINDOW_HEIGHT / 2.0)
			- (game->rays[i].wall_height / 2.0);
		if (game->rays[i].y_start < 0)
			game->rays[i].y_start = 0;
		game->rays[i].y_end = game->rays[i].y_start + game->rays[i].wall_height;
		get_texture_x(game, i, game->elements.north.image);
		while (game->rays[i].y_start < game->rays[i].y_end
			&& game->rays[i].y_start < WINDOW_HEIGHT)
		{
			get_texture_y(game, i, game->elements.north.image);
			draw_wall(game, i, game->vars.x_texures, game->vars.y_textures);
			game->rays[i].y_start++;
		}
	}
}
