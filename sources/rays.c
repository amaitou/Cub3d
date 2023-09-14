/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:45:11 by amait-ou          #+#    #+#             */
/*   Updated: 2023/09/14 09:10:02 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	dda(t_game *game)
{
	int		i;
	float	_x;
	float	_y;

	i = 0;
	game->dda.dx = cos(game->player.rotation_angle);
	game->dda.dy = sin(game->player.rotation_angle);
	_x = game->player.x;
	_y = game->player.y;
	while (game->map.map[(int)_y / TILE][(int)_x / TILE] != '1')
	{
		mlx_put_pixel(game->mlx.window,
			_x, _y, get_rgba(235, 52, 70, 255));
		_x += game->dda.dx;
		_y += game->dda.dy;
	}
}
