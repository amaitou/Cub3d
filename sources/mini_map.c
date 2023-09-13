/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 17:06:00 by amait-ou          #+#    #+#             */
/*   Updated: 2023/09/13 20:44:25 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	draw_player(int color, int y, int x, t_game *game)
{
	int	_x;
	int	_y;

	_y = -game->player.radius;
	while (_y <= game->player.radius)
	{
		_x = -game->player.radius;
		while (_x <= game->player.radius)
		{
			if (_x * _x + _y * _y <= game->player.radius * game->player.radius)
				mlx_put_pixel(game->mlx.window,
					_x + x, _y + y, color);
			++_x;
		}
		++_y;
	}
}

static void	draw_rectangle(int color, int y, int x, t_game *game)
{
	int	_x;
	int	_y;

	_y = 0;
	while (_y < TILE)
	{
		_x = 0;
		while (_x < TILE)
		{
			mlx_put_pixel(game->mlx.window, _x + x,
				_y + y, color);
			mlx_put_pixel(game->mlx.window, _x + x,
				y, get_rgba(0, 0, 0, 255));
			_x++;
		}
		mlx_put_pixel(game->mlx.window, x,
			_y + y, get_rgba(0, 0, 0, 255));
		_y++;
	}
}

void	draw_mini_map(t_game *game)
{
	int		y;
	int		x;
	char	*line;

	y = 0;
	while (game->map.map[y])
	{
		x = 0;
		line = game->map.map[y];
		while (line[x])
		{
			if (line[x] == '1')
				draw_rectangle(get_rgba(255, 248, 220, 255),
					y * TILE, x * TILE, game);
			else if (line[x] == '0' || ft_strchr("NEWS", line[x]))
				draw_rectangle(get_rgba(0, 118, 107, 255),
					y * TILE, x * TILE, game);
			++x;
		}
		++y;
	}
	draw_player(get_rgba(235, 52, 70, 255),
		game->player.y, game->player.x, game);
	dda(game->player.x, game->player.y, 2 * 30, 16 * 30, game);
}
