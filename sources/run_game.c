/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 11:51:42 by amait-ou          #+#    #+#             */
/*   Updated: 2023/09/29 11:58:38 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	mlx(t_game *game)
{
	game->mlx.mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "Cub3d", true);
	game->mlx.window = mlx_new_image(game->mlx.mlx,
			WINDOW_WIDTH, WINDOW_HEIGHT);
	mlx_image_to_window(game->mlx.mlx, game->mlx.window, 0, 0);
	mlx_loop_hook(game->mlx.mlx, check_keys, game);
}

void	set_angle(t_game *game)
{
	if (game->player.direction == 'N')
		game->player.rotation_angle = 270;
	else if (game->player.direction == 'W')
		game->player.rotation_angle = 180;
	else if (game->player.direction == 'E')
		game->player.rotation_angle = 0;
	else if (game->player.direction == 'S')
		game->player.rotation_angle = 90;
}

int	__run_game(t_game *game, int ac, char **ag)
{
	(void)ac;
	game->path = ag[1];
	init_all(game);
	if (__checker(game))
		return (1);
	set_angle(game);
	mlx(game);
	mlx_loop(game->mlx.mlx);
	return (0);
}
