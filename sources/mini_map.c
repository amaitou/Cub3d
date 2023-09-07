/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 17:06:00 by amait-ou          #+#    #+#             */
/*   Updated: 2023/09/07 16:51:37 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	draw_player(int color, int y, int x, t_game *game)
{
	int	r;
	int	_x;
	int	_y;

	r = SIZE / 8;
	_y = -r;
	while (_y <= r)
	{
		_x = -r;
		while (_x <= r)
		{
			if (_x * _x + _y * _y <= r * r)
			{
				mlx_put_pixel(game->mlx.window,
					_x + (x + SIZE / 2),
					_y + (y + SIZE / 2), color);
			}
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
	while (_y < SIZE)
	{
		_x = 0;
		while (_x < SIZE)
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
		ft_printf("[%d] -> [%s] -> [%d]\n", y, line, ft_strlen(line));
		while (line[x])
		{
			if (line[x] == '1')
				draw_rectangle(get_rgba(255, 248, 220, 255),
					y * SIZE, x * SIZE, game);
			else if (line[x] == '0' || ft_strchr("NEWS", line[x]))
				draw_rectangle(get_rgba(0, 118, 107, 255),
					y * SIZE, x * SIZE, game);
			++x;
		}
		++y;
	}
	draw_player(get_rgba(255, 0, 0, 255),
		game->player.y * SIZE, game->player.x * SIZE, game);
}
