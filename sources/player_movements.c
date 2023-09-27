/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1013/09/17 18:41:11 by amait-ou          #+#    #+#             */
/*   Updated: 2023/09/27 22:24:48 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	wall_hitting(t_game *game, float y, float x)
{
	if (game->map.map[(int)(y + 1) / TILE][(int)(x / TILE)] == '1')
		return (1);
	if (game->map.map[(int)(y - 1) / TILE][(int)(x / TILE)] == '1')
		return (1);
	if (game->map.map[(int)(y / TILE)][(int)(x + 1) / TILE] == '1')
		return (1);
	if (game->map.map[(int)(y / TILE)][(int)(x - 1) / TILE] == '1')
		return (1);
	return (0);
}

void	move_up(t_game *game)
{
	t_player	*player;
	float		x;
	float		y;

	player = &game->player;
	y = (player->y + sin(game->player.rotation_angle)
			* (game->player.move_speed));
	x = (player->x + cos(game->player.rotation_angle)
			* (game->player.move_speed));
	if (wall_hitting(game, y, x))
		return ;
	if (game->map.map[(int)y / TILE][(int)x / TILE] != '1')
	{
		player->x += cos(game->player.rotation_angle) * game->player.move_speed;
		player->y += sin(game->player.rotation_angle) * game->player.move_speed;
	}
	return ;
}

void	move_down(t_game *game)
{
	t_player	*player;
	float		x;
	float		y;

	player = &game->player;
	y = (player->y - sin(game->player.rotation_angle)
			* (game->player.move_speed));
	x = (player->x - cos(game->player.rotation_angle)
			* (game->player.move_speed));
	if (wall_hitting(game, y, x))
		return ;
	if (game->map.map[(int)y / TILE][(int)x / TILE] != '1')
	{
		player->x -= cos(game->player.rotation_angle) * game->player.move_speed;
		player->y -= sin(game->player.rotation_angle) * game->player.move_speed;
	}
	return ;
}

void	move_left(t_game *game)
{
	t_player	*player;
	float		x;
	float		y;

	player = &game->player;
	y = (player->y + sin(game->player.rotation_angle - (M_PI / 2))
			* (game->player.move_speed));
	x = (game->player.x + cos(game->player.rotation_angle - (M_PI / 2))
			* (game->player.move_speed));
	if (wall_hitting(game, y, x))
		return ;
	if (game->map.map[(int)y / TILE][(int)x / TILE] != '1')
	{
		player->x += cos(game->player.rotation_angle - (M_PI / 2))
			* game->player.move_speed;
		player->y += sin(game->player.rotation_angle - (M_PI / 2))
			* game->player.move_speed;
	}
	return ;
}

void	move_right(t_game *game)
{
	t_player	*player;
	float		x;
	float		y;

	player = &game->player;
	y = (player->y - sin(game->player.rotation_angle - (M_PI / 2))
			* (game->player.move_speed));
	x = (game->player.x - cos(game->player.rotation_angle - (M_PI / 2))
			* (game->player.move_speed));
	if (wall_hitting(game, y, x))
		return ;
	if (game->map.map[(int)y / TILE][(int)x / TILE] != '1')
	{
		player->x -= cos(game->player.rotation_angle - (M_PI / 2))
			* game->player.move_speed;
		player->y -= sin(game->player.rotation_angle - (M_PI / 2))
			* game->player.move_speed;
	}
	return ;
}
