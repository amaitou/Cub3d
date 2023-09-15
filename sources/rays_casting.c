/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_casting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:45:11 by amait-ou          #+#    #+#             */
/*   Updated: 2023/09/16 00:29:44 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	check_helper(char **_m, int _y, int _x, char c)
{
	if ((_m[_y / TILE][(_x - 1) / TILE] == c
		&& _m[(_y + 1) / TILE][_x / TILE] == c)
		|| (_m[_y / TILE][(_x + 1) / TILE] == c
			&& _m[(_y - 1) / TILE][_x / TILE] == c)
		|| (_m[_y / TILE][(_x - 1) / TILE] == c
			&& _m[(_y - 1) / TILE][_x / TILE] == c)
		|| (_m[_y / TILE][(_x + 1) / TILE] == c
			&& _m[(_y + 1) / TILE][_x / TILE] == c))
		return (1);
	return (0);
}

void	dda(t_game *game, float angle)
{
	float	_x;
	float	_y;

	_x = game->player.x;
	_y = game->player.y;
	while (game->map.map[(int)_y / TILE][(int)_x / TILE] != '1')
	{
		if (check_helper(game->map.map, (int)_y, (int)_x, '1'))
			break ;
		if (check_helper(game->map.map, (int)_y, (int)_x, ' '))
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
