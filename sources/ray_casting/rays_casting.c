/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_casting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:45:11 by amait-ou          #+#    #+#             */
/*   Updated: 2023/10/03 03:01:22 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static float	distance_of_2_points(float x1, float y1, float x2, float y2)
{
	return (sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)));
}

static void	was_hit_vertical(t_game *game, int i)
{
	if (game->rays[i].v_distance < game->rays[i].h_distance)
		game->rays[i].was_hit_vertical = 1;
	else
		game->rays[i].was_hit_vertical = 0;
}

static void	calculate_distances(t_game *game, int i)
{
	if (game->vars.found_h_wall)
		game->rays[i].h_distance = distance_of_2_points(game->player.x,
				game->player.y, game->rays[i].h_wall_hit_x,
				game->rays[i].h_wall_hit_y);
	else
		game->rays[i].h_distance = INT_MAX;
	if (game->vars.found_v_wall)
		game->rays[i].v_distance = distance_of_2_points(game->player.x,
				game->player.y, game->rays[i].v_wall_hit_x,
				game->rays[i].v_wall_hit_y);
	else
		game->rays[i].v_distance = INT_MAX;
	if (game->rays[i].h_distance < game->rays[i].v_distance)
	{
		game->rays[i].wall_hit_x = game->rays[i].h_wall_hit_x;
		game->rays[i].wall_hit_y = game->rays[i].h_wall_hit_y;
		game->rays[i].distance = game->rays[i].h_distance;
	}
	else
	{
		game->rays[i].wall_hit_x = game->rays[i].v_wall_hit_x;
		game->rays[i].wall_hit_y = game->rays[i].v_wall_hit_y;
		game->rays[i].distance = game->rays[i].v_distance;
	}
	was_hit_vertical(game, i);
}

void	cast_rays(t_game *game)
{
	float	ray_angle;
	float	steps;
	int		i;

	ray_angle = game->player.rotation_angle - (game->player.fov / 2);
	steps = game->player.fov / WINDOW_WIDTH;
	i = 0;
	while (i < WINDOW_WIDTH)
	{
		normalize_angle(&ray_angle);
		h_intersection(game, ray_angle, i);
		v_intersection(game, ray_angle, i);
		game->rays[i].angle = ray_angle;
		calculate_distances(game, i);
		ray_angle += steps;
		++i;
	}
}
