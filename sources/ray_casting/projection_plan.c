/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_plan.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 15:54:57 by amait-ou          #+#    #+#             */
/*   Updated: 2023/10/03 23:23:15 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	draw_wall(t_game *game, int index)
{
	if (game->rays[index].direction == _NORTH)
		mlx_put_pixel(game->mlx.image, index, game->rays[index].y_start,
			get_rgba(255, 0, 0, 255));
	else if (game->rays[index].direction == _SOUTH)
		mlx_put_pixel(game->mlx.image, index, game->rays[index].y_start,
			get_rgba(0, 153, 0, 255));
	else if (game->rays[index].direction == _EAST)
		mlx_put_pixel(game->mlx.image, index, game->rays[index].y_start,
			get_rgba(255, 255, 0, 255));
	else if (game->rays[index].direction == _WEST)
		mlx_put_pixel(game->mlx.image, index, game->rays[index].y_start,
			get_rgba(102, 51, 0, 255));
}

void	projection_plan(t_game *game)
{
	size_t	i;

	i = 0;
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
		game->rays[i].y_end = game->rays[i].y_start + game->rays[i].wall_height;
		while (game->rays[i].y_start < game->rays[i].y_end)
		{
			draw_wall(game, i);
			game->rays[i].y_start++;
		}
		++i;
	}
}
