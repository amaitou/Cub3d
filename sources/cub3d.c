/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 15:06:11 by amait-ou          #+#    #+#             */
/*   Updated: 2023/09/29 10:49:32 by amait-ou         ###   ########.fr       */
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

int	main(int ac, char **ag)
{
	t_game	*game;

	if (ac == 2)
	{
		game = (t_game *)malloc(sizeof(t_game));
		if (!game)
		{
			ft_putendl_fd("Error: Failed To Run The Game", 2);
			return (0);
		}
		game->path = ag[1];
		init_all(game);
		if (__checker(game))
			return (EXIT_FAILURE);
		set_angle(game);
		mlx(game);
		mlx_loop(game->mlx.mlx);
	}
	else
	{
		ft_putendl_fd("Error: Invalid Arguments", 2);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
