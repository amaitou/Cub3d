/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 19:08:37 by amait-ou          #+#    #+#             */
/*   Updated: 2023/10/03 01:50:23 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_rays(t_game *game)
{
	int	i;

	i = 0;
	while (i < WINDOW_WIDTH)
	{
		draw_line(game,
			game->rays[i].wall_hit_x, game->rays[i].wall_hit_y);
		++i;
	}
}

void	draw_game(t_game *game)
{
	clear_map(game);
	draw_ceiling(game);
	draw_floor(game);
	projection_plan(game);
	draw_mini_map(game);
	cast_rays(game);
	draw_rays(game);
	// free(game->rays);
}
