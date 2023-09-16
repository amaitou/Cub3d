/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 17:51:09 by amait-ou          #+#    #+#             */
/*   Updated: 2023/09/16 19:56:02 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	move_up(t_game *game)
{
	t_player	*player;
	float		x;
	float		y;

	player = &game->player;
	y = (player->y + sin(game->player.rotation_angle)
			* (game->player.move_speed) + (1)) / TILE;
	x = (player->x + cos(game->player.rotation_angle) + (1)) / TILE;
	if (game->map.map[(int)y][(int)x] != '1')
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
			* (game->player.move_speed) + (1)) / TILE;
	x = (player->x - cos(game->player.rotation_angle) + (1)) / TILE;
	if (game->map.map[(int)y][(int)x] != '1')
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
	y = (player->y + sin(game->player.rotation_angle) + (1)) / TILE;
	x = (game->player.x + cos(game->player.rotation_angle)
			* (game->player.move_speed) + (1)) / TILE ;
	if (game->map.map[(int)y][(int)x] != '1')
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
	y = (player->y - sin(game->player.rotation_angle) + (1)) / TILE;
	x = (game->player.x - cos(game->player.rotation_angle)
			* (game->player.move_speed) + (1)) / TILE;
	if (game->map.map[(int)y][(int)x] != '1')
	{
		player->x -= cos(game->player.rotation_angle - (M_PI / 2))
			* game->player.move_speed;
		player->y -= sin(game->player.rotation_angle - (M_PI / 2))
			* game->player.move_speed;
	}
	return ;
}
