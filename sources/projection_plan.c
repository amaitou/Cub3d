/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_plan.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 15:54:57 by amait-ou          #+#    #+#             */
/*   Updated: 2023/10/02 23:44:56 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
			mlx_put_pixel(game->mlx.window, i, game->rays[i].y_start,
				get_rgba(77, 0, 25, 255));
			game->rays[i].y_start++;
		}
		++i;
	}
}
