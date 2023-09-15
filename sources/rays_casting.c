/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_casting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:45:11 by amait-ou          #+#    #+#             */
/*   Updated: 2023/09/15 21:06:56 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	dda(t_game *game, float angle)
{
	float	_x;
	float	_y;

	_x = game->player.x;
	_y = game->player.y;
	while (game->map.map[(int)_y / TILE][(int)_x / TILE] != '1')
	{
		if ((game->map.map[(int)_y / TILE][(int)(_x - 1) / TILE] == '1' && game->map.map[(int)(_y + 1) / TILE][(int)_x / TILE] == '1')
			|| (game->map.map[(int)_y / TILE][(int)(_x + 1) / TILE] == '1' && game->map.map[(int)(_y - 1) / TILE][(int)_x / TILE] == '1')
			|| (game->map.map[(int)_y / TILE][(int)(_x - 1) / TILE] == '1' && game->map.map[(int)(_y - 1) / TILE][(int)_x / TILE] == '1')
			|| (game->map.map[(int)_y / TILE][(int)(_x + 1) / TILE] == '1' && game->map.map[(int)(_y + 1) / TILE][(int)_x / TILE] == '1'))
			break ;
		if ((game->map.map[(int)_y / TILE][(int)(_x - 1) / TILE] == '1' && game->map.map[(int)(_y + 1) / TILE][(int)_x / TILE] == ' ')
			|| (game->map.map[(int)_y / TILE][(int)(_x + 1) / TILE] == '1' && game->map.map[(int)(_y - 1) / TILE][(int)_x / TILE] == ' ')
			|| (game->map.map[(int)_y / TILE][(int)(_x - 1) / TILE] == '1' && game->map.map[(int)(_y - 1) / TILE][(int)_x / TILE] == ' ')
			|| (game->map.map[(int)_y / TILE][(int)(_x + 1) / TILE] == '1' && game->map.map[(int)(_y + 1) / TILE][(int)_x / TILE] == ' '))
			break ;
		game->dda.dx = cos(angle);
		game->dda.dy = sin(angle);
		mlx_put_pixel(game->mlx.window,
			_x, _y, get_rgba(235, 52, 70, 255));
		_x += game->dda.dx;
		_y += game->dda.dy;
	}
}

void	draw_rays(t_game *game)
{
	float	angle;
	float	step;
	size_t	i;

	angle = game->player.rotation_angle - (30 * (M_PI / 180));
	step = (60 * (M_PI / 180)) / (game->map.width * TILE);
	i = 0;
	while (i < game->map.width * TILE)
	{
		dda(game, angle);
		angle += step;
		++i;
	}
}
