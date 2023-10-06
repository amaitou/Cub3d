/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhalil- <ykhalil-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 20:34:15 by amait-ou          #+#    #+#             */
/*   Updated: 2023/10/06 11:30:02 by ykhalil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	load_textures(t_game *game)
{
	game->elements.north.image = mlx_load_png(game->elements.north.texture);
	if (!game->elements.north.image)
		return (1);
	game->elements.south.image = mlx_load_png(game->elements.south.texture);
	if (!game->elements.south.image)
		return (1);
	game->elements.west.image = mlx_load_png(game->elements.west.texture);
	if (!game->elements.west.image)
		return (1);
	game->elements.east.image = mlx_load_png(game->elements.east.texture);
	if (!game->elements.east.image)
		return (1);
	return (0);
}

int	get_color_of_texture(int x, int y, mlx_texture_t *image)
{
	int	index;

	index = ((y * image->width) + x) * image->bytes_per_pixel;
	return (get_rgba(
			image->pixels[index + 0],
			image->pixels[index + 1],
			image->pixels[index + 2],
			image->pixels[index + 3]));
}

void	get_texture_x(t_game *game, int index, mlx_texture_t *image)
{
	if (game->rays[index].was_hit_vertical == 1)
	{
		game->vars.x_texures = fmod(game->rays[index].wall_hit_y, TILE)
			* (image->width / TILE);
	}
	else
	{
		if (game->rays[index].wall_hit_x >= 0
			&& game->rays[index].wall_hit_x < WINDOW_WIDTH)
			game->vars.x_texures = fmod(game->rays[index].wall_hit_x, TILE)
				* (image->width / TILE);
	}
}

void	get_texture_y(t_game *game, int index, mlx_texture_t *image)
{
	if (game->rays[index].y_start > 0
		&& game->rays[index].y_start < WINDOW_HEIGHT)
		game->vars.y_textures = (1 - (game->rays[index].y_end
					- game->rays[index].y_start)
				/ game->rays[index].wall_height) * image->height;
}

void	detect_texture(t_game *game, int index)
{
	if (game->rays[index].direction == _NORTH)
		game->vars.image = game->elements.north.image;
	else if (game->rays[index].direction == _SOUTH)
		game->vars.image = game->elements.south.image;
	else if (game->rays[index].direction == _WEST)
		game->vars.image = game->elements.west.image;
	else if (game->rays[index].direction == _EAST)
		game->vars.image = game->elements.east.image;
}
