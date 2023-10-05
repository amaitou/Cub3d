/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_plan.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 15:54:57 by amait-ou          #+#    #+#             */
/*   Updated: 2023/10/04 23:43:43 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	get_color(int x, int y, mlx_texture_t *image)
{
	// if (x < 0 || y < 0 || x > (int)image->width || y > (int)image->height)
	// 	return (0);
	int	index = ((y * image->width) + x) * image->bytes_per_pixel;
	return (get_rgba(image->pixels[index + 0], image->pixels[index + 1], image->pixels[index + 2], image->pixels[index + 3]));
}

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
	mlx_put_pixel(game->mlx.image, index, game->rays[index].y_start, get_color(x, y, game->elements.north.image));
}
void	projection_plan(t_game *game)
{
	size_t	i;
	float	x_texture;
	float	y_texture;

	i = 0;
	printf("%u, %u\n", game->elements.north.image->width, game->elements.north.image->height);
	while (i < WINDOW_WIDTH)
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
		if (game->rays[i].was_hit_vertical == 1)
			x_texture = fmod(game->rays[i].wall_hit_y, TILE) * (game->elements.north.image->width / TILE);
		else
			x_texture = fmod(game->rays[i].wall_hit_x, TILE) * (game->elements.north.image->width / TILE);
		while (game->rays[i].y_start < game->rays[i].y_end && game->rays[i].y_start < WINDOW_HEIGHT)
		{
			y_texture = (1 - (game->rays[i].y_end - game->rays[i].y_start) / game->rays[i].wall_height) * game->elements.north.image->height;
			draw_wall(game, i, x_texture, y_texture);
			game->rays[i].y_start++;
		}
		++i;
	}
}
