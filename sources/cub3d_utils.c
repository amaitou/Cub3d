/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:42:25 by amait-ou          #+#    #+#             */
/*   Updated: 2023/09/06 19:53:40 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_members(t_game *game)
{
	game->east = 0;
	game->north = 0;
	game->west = 0;
	game->south = 0;
	game->map.height = 0;
	game->map.width = 0;
}

int	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	mlx(t_game *game)
{
	size_t	height;
	size_t	width;

	height = game->map.height * SIZE;
	width = game->map.width * SIZE;
	game->mlx.mlx = mlx_init(width, height, "GWW9", true);
	game->mlx.window = mlx_new_image(game->mlx.mlx,
			game->map.width * SIZE, game->map.height * SIZE);
	mlx_image_to_window(game->mlx.mlx, game->mlx.window, 0, 0);
	draw_mini_map(game);
}
