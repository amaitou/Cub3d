/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 18:49:49 by amait-ou          #+#    #+#             */
/*   Updated: 2023/09/10 19:43:56 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	check_keys(void *game)
{
	t_game	*g;

	g = (t_game *)game;
	if (mlx_is_key_down(g->mlx.mlx, MLX_KEY_W))
		move_up(g);
	else if (mlx_is_key_down(g->mlx.mlx, MLX_KEY_S))
		move_down(g);
	else if (mlx_is_key_down(g->mlx.mlx, MLX_KEY_A))
		move_left(g);
	else if (mlx_is_key_down(g->mlx.mlx, MLX_KEY_D))
		move_right(g);
	draw_mini_map(g);
	return ;
}
