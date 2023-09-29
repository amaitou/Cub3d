/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_casting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:45:11 by amait-ou          #+#    #+#             */
/*   Updated: 2023/09/29 17:09:54 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	check_helper(char **_m, float _y, float _x, char c)
{
	if ((_m[(int)_y / TILE][(int)(_x - 0.1) / TILE] == c
		&& _m[(int)(_y + 0.1) / TILE][(int)_x / TILE] == c)
		|| (_m[(int)_y / TILE][(int)(_x + 0.1) / TILE] == c
			&& _m[(int)(_y - 0.1) / TILE][(int)_x / TILE] == c)
		|| (_m[(int)_y / TILE][(int)(_x - 0.1) / TILE] == c
			&& _m[(int)(_y - 0.1) / TILE][(int)_x / TILE] == c)
		|| (_m[(int)_y / TILE][(int)(_x + 0.1) / TILE] == c
			&& _m[(int)(_y + 0.1) / TILE][(int)_x / TILE] == c))
		return (1);
	return (0);
}

void	dda(t_game *game, float angle)
{
	game->player.dda_x = game->player.x;
	game->player.dda_y = game->player.y;
	while (game->map.map[(int)game->player.dda_y / TILE]
		[(int)game->player.dda_x / TILE] != '1')
	{
		if (check_helper(game->map.map, game->player.dda_y,
				game->player.dda_x, '1'))
			break ;
		mlx_put_pixel(game->mlx.window,
			game->player.dda_x, game->player.dda_y, get_rgba(235, 52, 70, 255));
		game->player.dda_x += cos(angle) * 0.09;
		game->player.dda_y += sin(angle) * 0.09;
	}
}

void	draw_rays(t_game *game)
{
	float	angle;
	float	step;
	size_t	i;

	angle = game->player.rotation_angle - (radial(game->player.fov) / 2);
	step = radial(game->player.fov) / WINDOW_WIDTH;
	i = 0;
	while (i < WINDOW_WIDTH)
	{
		dda(game, angle);
		game->ray[i].x = game->player.dda_x;
		game->ray[i].y = game->player.dda_y;
		game->ray[i].angle = angle;
		angle += step;
		i++;
	}
}
