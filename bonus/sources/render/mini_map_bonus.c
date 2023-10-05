/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 17:06:00 by amait-ou          #+#    #+#             */
/*   Updated: 2023/10/05 16:49:57 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	draw_player(int color, float y, float x, t_game *game)
{
	float	_x;
	float	_y;

	_y = -game->player.radius;
	while (_y <= game->player.radius)
	{
		_x = -game->player.radius;
		while (_x <= game->player.radius)
		{
			if (_x * _x + _y * _y <= game->player.radius * game->player.radius)
				mlx_put_pixel(game->mlx.image,
					_x + x, _y + y, color);
			++_x;
		}
		++_y;
	}
}

static void	draw_rectangle(int color, float y, float x, t_game *game)
{
	float	_x;
	float	_y;

	_y = 0;
	while (_y < TILE)
	{
		_x = 0;
		while (_x < TILE)
		{
			mlx_put_pixel(game->mlx.image, _x + x,
				_y + y, color);
			mlx_put_pixel(game->mlx.image, _x + x,
				y, get_rgba(0, 0, 0, 255));
			_x++;
		}
		mlx_put_pixel(game->mlx.image, x,
			_y + y, get_rgba(0, 0, 0, 255));
		_y++;
	}
}

void	draw_mini_map(t_game *game)
{
	float		y;
	float		x;
	char		*line;

	y = 0;
	while (game->map.map[(int)y])
	{
		x = 0;
		line = game->map.map[(int)y];
		while (line[(int)x])
		{
			if (line[(int)x] == '1')
				draw_rectangle(get_rgba(255, 248, 220, 255),
					y * TILE, x * TILE, game);
			else if (line[(int)x] == '0' || ft_strchr("NEWS", line[(int)x]))
				draw_rectangle(get_rgba(0, 118, 107, 255),
					y * TILE, x * TILE, game);
			++x;
		}
		++y;
	}
	draw_player(get_rgba(252, 3, 219, 255),
		game->player.y, game->player.x, game);
}
