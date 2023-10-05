/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_plan.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 15:54:57 by amait-ou          #+#    #+#             */
/*   Updated: 2023/10/05 10:46:13 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	draw_wall(t_game *game, int index, int x, int y)
{
	if (game->rays[index].y_start >= 0
		&& game->rays[index].y_start < WINDOW_HEIGHT)
		mlx_put_pixel(game->mlx.image, index, game->rays[index].y_start,
			get_color_of_texture(x, y, game->vars.image));
}

static void	render_texture(t_game *game, int index)
{
	while (game->rays[index].y_start < game->rays[index].y_end
		&& game->rays[index].y_start < WINDOW_HEIGHT)
	{
		get_texture_y(game, index, game->vars.image);
		draw_wall(game, index, game->vars.x_texures, game->vars.y_textures);
		game->rays[index].y_start++;
	}
}

void	projection_plan(t_game *game)
{
	size_t	index;

	index = 0;
	while (index < WINDOW_WIDTH)
	{
		fix_fish_eye(game, index);
		calculate_wall_height(game, index);
		calculate_starting_point_of_the_wall(game, index);
		calculate_ending_point_of_the_wall(game, index);
		detect_texture(game, index);
		get_texture_x(game, index, game->vars.image);
		render_texture(game, index);
		++index;
	}
}
