/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 17:50:03 by amait-ou          #+#    #+#             */
/*   Updated: 2023/09/17 18:39:55 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	wall_hitting(t_game *game, int y, int x)
{
	if (game->map.map[(y + 3) / TILE][x / TILE] == '1')
		return (1);
	if (game->map.map[(y - 3) / TILE][x / TILE] == '1')
		return (1);
	if (game->map.map[y / TILE][(x + 3) / TILE] == '1')
		return (1);
	if (game->map.map[y / TILE][(x - 3) / TILE] == '1')
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
	x = (player->x + cos(game->player.rotation_angle));
	if (wall_hitting(game, (int)y, (int)x))
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
	x = (player->x - cos(game->player.rotation_angle));
	if (wall_hitting(game, (int)y, (int)x))
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
	y = (player->y + sin(game->player.rotation_angle - (M_PI / 2)));
	x = (game->player.x + cos(game->player.rotation_angle - (M_PI / 2))
			* (game->player.move_speed));
	if (wall_hitting(game, (int)y, (int)x))
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
	y = (player->y - sin(game->player.rotation_angle - (M_PI / 2)));
	x = (game->player.x - cos(game->player.rotation_angle - (M_PI / 2))
			* (game->player.move_speed));
	if (wall_hitting(game, (int)y, (int)x))
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
