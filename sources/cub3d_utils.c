/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:42:25 by amait-ou          #+#    #+#             */
/*   Updated: 2023/09/10 19:08:55 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	mlx(t_game *game)
{
	size_t	height;
	size_t	width;

	height = game->map.height * TILE;
	width = game->map.width * TILE;
	game->mlx.mlx = mlx_init(width, height, "Cub3d", true);
	game->mlx.window = mlx_new_image(game->mlx.mlx,
			game->map.width * TILE, game->map.height * TILE);
	mlx_image_to_window(game->mlx.mlx, game->mlx.window, 0, 0);
	mlx_loop_hook(game->mlx.mlx, check_keys, game);
}
