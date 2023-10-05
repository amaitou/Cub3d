/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_intersection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 13:53:18 by amait-ou          #+#    #+#             */
/*   Updated: 2023/10/03 03:01:07 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	ray_facing(t_game *game, float ray_angle)
{
	game->vars.ray_facing_down = ray_angle > 0 && ray_angle < M_PI;
	game->vars.ray_facing_up = !game->vars.ray_facing_down;
	game->vars.ray_facing_right = ray_angle < 0.5 * M_PI
		|| ray_angle > 1.5 * M_PI;
	game->vars.ray_facing_left = !game->vars.ray_facing_right;
}

static int	is_wall(t_game *game, float x, float y)
{
	float	_x;
	float	_y;

	if (x < 0 || x >= WINDOW_WIDTH || y < 0 || y >= WINDOW_HEIGHT)
		return (1);
	_x = floor(x / TILE);
	_y = floor(y / TILE);
	if (_y >= game->map.height)
		return (1);
	if (_x >= ft_strlen(game->map.map[(int)_y]))
		return (1);
	if (game->map.map[(int)_y][(int)_x] == '1')
		return (1);
	return (0);
}

static void	calculate_intercepts(t_game *game, float ray_angle)
{
	game->vars.y_intercept = floor((game->player.y / TILE)) * TILE;
	if (game->vars.ray_facing_down)
		game->vars.y_intercept += TILE;
	else
		game->vars.y_intercept += 0;
	game->vars.x_intercept = game->player.x
		+ ((game->vars.y_intercept - game->player.y) / tan(ray_angle));
}

static void	calculate_steps(t_game *game, float ray_angle)
{
	game->vars.y_step = TILE;
	if (game->vars.ray_facing_up)
		game->vars.y_step *= -1;
	else
		game->vars.y_step *= 1;
	game->vars.x_step = TILE / tan(ray_angle);
	if (game->vars.ray_facing_left && game->vars.x_step > 0)
		game->vars.x_step *= -1;
	else
		game->vars.x_step *= 1;
	if (game->vars.ray_facing_right && game->vars.x_step < 0)
		game->vars.x_step *= -1;
	else
		game->vars.x_step *= 1;
	game->vars.found_h_wall = 0;
}

void	h_intersection(t_game *game, float ray_angle, int index)
{
	ray_facing(game, ray_angle);
	calculate_intercepts(game, ray_angle);
	calculate_steps(game, ray_angle);
	game->vars.next_x = game->vars.x_intercept;
	game->vars.next_y = game->vars.y_intercept;
	game->vars.added_pixel = 0;
	if (game->vars.ray_facing_up)
		game->vars.added_pixel = 1;
	while (game->vars.next_x >= 0 && game->vars.next_x <= WINDOW_WIDTH
		&& game->vars.next_y >= 0 && game->vars.next_y <= WINDOW_HEIGHT)
	{
		if (is_wall(game, game->vars.next_x,
				game->vars.next_y - game->vars.added_pixel))
		{
			game->rays[index].h_wall_hit_x = game->vars.next_x;
			game->rays[index].h_wall_hit_y = game->vars.next_y;
			game->vars.found_h_wall = 1;
			break ;
		}
		else
		{
			game->vars.next_x += game->vars.x_step;
			game->vars.next_y += game->vars.y_step;
		}
	}
}
