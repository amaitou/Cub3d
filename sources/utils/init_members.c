/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_members.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 17:26:12 by amait-ou          #+#    #+#             */
/*   Updated: 2023/10/03 03:01:53 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	init_directions(t_game *game)
{
	game->east = 0;
	game->north = 0;
	game->west = 0;
	game->south = 0;
}

static void	init_map(t_game *game)
{
	game->map.height = 0;
	game->map.width = 0;
}

static void	init_elements(t_game *game)
{
	game->elements.ceiling_c.type = _NONE;
	game->elements.ceiling_c.surface = NULL;
	game->elements.ceiling_c.rgb = NULL;
	game->elements.floor_c.type = _NONE;
	game->elements.floor_c.surface = NULL;
	game->elements.floor_c.rgb = NULL;
	game->elements.north.direction = _NONE;
	game->elements.north.texture = NULL;
	game->elements.south.direction = _NONE;
	game->elements.south.texture = NULL;
	game->elements.east.direction = _NONE;
	game->elements.east.texture = NULL;
	game->elements.west.direction = _NONE;
	game->elements.west.texture = NULL;
	game->elements.counter = 0;
}

static void	init_player(t_game *game)
{
	game->player.x = 0.00;
	game->player.y = 0.00;
	game->player.radius = RADIUS;
	game->player.rotation_angle = 0.00 * (M_PI / 180);
	game->player.turn_direction = 0.00;
	game->player.walk_direction = 0.00;
	game->player.move_speed = MOVE_SPEED;
	game->player.fov = FIELD_OF_VIEW * (M_PI / 180);
}

void	init_all(t_game *game)
{
	init_directions(game);
	init_map(game);
	init_elements(game);
	init_player(game);
	game->rays = (t_rays *)malloc(sizeof(t_rays) * WINDOW_WIDTH);
}
