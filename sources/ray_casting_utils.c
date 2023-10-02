/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 17:42:32 by amait-ou          #+#    #+#             */
/*   Updated: 2023/09/30 19:17:26 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

float	radial(float number)
{
	return (number * (M_PI / 180.0));
}

void	draw_line(t_game *game, float x1, float y1)
{
	int		i;
	float	x;
	float	y;

	game->dda.dx = x1 - game->player.x;
	game->dda.dy = y1 - game->player.y;
	if (abs(game->dda.dx) > abs(game->dda.dy))
		game->dda.steps = abs(game->dda.dx);
	else
		game->dda.steps = abs(game->dda.dy);
	game->dda.xinc = game->dda.dx / (float)game->dda.steps;
	game->dda.yinc = game->dda.dy / (float)game->dda.steps;
	x = game->player.x;
	y = game->player.y;
	i = 0;
	while (i <= game->dda.steps)
	{
		mlx_put_pixel(game->mlx.window, round(x), round(y),
			get_rgba(255, 0, 0, 255));
		x += game->dda.xinc;
		y += game->dda.yinc;
		++i;
	}
}
