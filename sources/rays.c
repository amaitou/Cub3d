/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:45:11 by amait-ou          #+#    #+#             */
/*   Updated: 2023/09/13 21:18:13 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	_abs(int v)
{
	if (v < 0)
		return (v * (-1));
	return (v);
}

static int	_steps(int dx, int dy)
{
	if (_abs(dx) > _abs(dy))
		return (_abs(dx));
	return (_abs(dy));
}

void	dda(t_game *game, int x, int y)
{
	int		i;
	float	_x;
	float	_y;

	i = 0;
	game->dda.dx = x - game->player.x;
	game->dda.dy = y - game->player.y;
	game->dda.steps = _steps(game->dda.dx, game->dda.dy);
	game->dda.xinc = game->dda.dx / (float)game->dda.steps;
	game->dda.yinc = game->dda.dy / (float)game->dda.steps;
	_x = game->player.x;
	_y = game->player.y;
	while (i <= game->dda.steps)
	{
		printf("(%d, %d)\n", (int)_x, (int)_y);
		mlx_put_pixel(game->mlx.window,
			round(_x), round(_y), get_rgba(235, 52, 70, 255));
		_x += game->dda.xinc;
		_y += game->dda.yinc;
		++i;
	}
}
