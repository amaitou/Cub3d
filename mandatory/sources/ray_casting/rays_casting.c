/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_casting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:45:11 by amait-ou          #+#    #+#             */
/*   Updated: 2023/10/05 03:15:29 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static float	distance_of_2_points(float x1, float y1, float x2, float y2)
{
	return (sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)));
}

static void	was_hit_vertical(t_game *game, int index)
{
	if (game->rays[index].v_distance < game->rays[index].h_distance)
	{
		game->rays[index].was_hit_vertical = 1;
		if (cos(game->rays[index].angle) > 0)
			game->rays[index].direction = _EAST;
		else
			game->rays[index].direction = _WEST;
	}
	else
	{
		game->rays[index].was_hit_vertical = 0;
		if (sin(game->rays[index].angle) > 0)
			game->rays[index].direction = _SOUTH;
		else
			game->rays[index].direction = _NORTH;
	}
}

static void	calculate_distances(t_game *game, int index)
{
	if (game->vars.found_h_wall)
		game->rays[index].h_distance = distance_of_2_points(game->player.x,
				game->player.y, game->rays[index].h_wall_hit_x,
				game->rays[index].h_wall_hit_y);
	else
		game->rays[index].h_distance = INT_MAX;
	if (game->vars.found_v_wall)
		game->rays[index].v_distance = distance_of_2_points(game->player.x,
				game->player.y, game->rays[index].v_wall_hit_x,
				game->rays[index].v_wall_hit_y);
	else
		game->rays[index].v_distance = INT_MAX;
	if (game->rays[index].h_distance < game->rays[index].v_distance)
	{
		game->rays[index].wall_hit_x = game->rays[index].h_wall_hit_x;
		game->rays[index].wall_hit_y = game->rays[index].h_wall_hit_y;
		game->rays[index].distance = game->rays[index].h_distance;
	}
	else
	{
		game->rays[index].wall_hit_x = game->rays[index].v_wall_hit_x;
		game->rays[index].wall_hit_y = game->rays[index].v_wall_hit_y;
		game->rays[index].distance = game->rays[index].v_distance;
	}
	was_hit_vertical(game, index);
}

void	cast_rays(t_game *game)
{
	float	ray_angle;
	float	steps;
	int		index;

	ray_angle = game->player.rotation_angle - (game->player.fov / 2);
	steps = game->player.fov / WINDOW_WIDTH;
	index = 0;
	while (index < WINDOW_WIDTH)
	{
		normalize_angle(&ray_angle);
		h_intersection(game, ray_angle, index);
		v_intersection(game, ray_angle, index);
		game->rays[index].angle = ray_angle;
		calculate_distances(game, index);
		ray_angle += steps;
		++index;
	}
}
