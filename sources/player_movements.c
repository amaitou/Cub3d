/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 17:51:09 by amait-ou          #+#    #+#             */
/*   Updated: 2023/09/13 19:26:25 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	move_up(t_game *game)
{
	t_player	*player;
	float		x;
	float		y;

	player = &game->player;
	y = (game->player.y - player->move_speed) / TILE;
	x = player->x / TILE;
	if (game->map.map[(int)y][(int)x] != '1')
		player->y -= player->move_speed;
	return ;
}

void	move_down(t_game *game)
{
	t_player	*player;
	float		x;
	float		y;

	player = &game->player;
	y = (game->player.y + player->move_speed) / TILE;
	x = player->x / TILE;
	if (game->map.map[(int)y][(int)x] != '1')
		player->y += player->move_speed;
	return ;
}

void	move_right(t_game *game)
{
	t_player	*player;
	float		x;
	float		y;

	player = &game->player;
	y = player->y / TILE;
	x = (player->x + player->move_speed) / TILE;
	if (game->map.map[(int)y][(int)x] != '1')
		player->x += player->move_speed;
	return ;
}

void	move_left(t_game *game)
{
	t_player	*player;
	float		x;
	float		y;

	player = &game->player;
	y = player->y / TILE;
	x = (player->x - player->move_speed) / TILE;
	if (game->map.map[(int)y][(int)x] != '1')
		player->x -= player->move_speed;
	return ;
}
