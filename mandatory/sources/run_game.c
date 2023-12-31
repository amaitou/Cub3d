/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 11:51:42 by amait-ou          #+#    #+#             */
/*   Updated: 2023/10/05 17:09:46 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	mlx(t_game *game)
{
	game->mlx.mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "Casa Negra", true);
	game->mlx.image = mlx_new_image(game->mlx.mlx,
			WINDOW_WIDTH, WINDOW_HEIGHT);
	mlx_image_to_window(game->mlx.mlx, game->mlx.image, 0, 0);
	mlx_loop_hook(game->mlx.mlx, check_keys, game);
}

static void	set_angle(t_game *game)
{
	if (game->player.direction == 'N')
		game->player.rotation_angle = 270 * (M_PI / 180);
	else if (game->player.direction == 'W')
		game->player.rotation_angle = 180 * (M_PI / 180);
	else if (game->player.direction == 'E')
		game->player.rotation_angle = 0 * (M_PI / 180);
	else if (game->player.direction == 'S')
		game->player.rotation_angle = 90 * (M_PI / 180);
}

static void	set_colors(t_game *game)
{
	char	**floor;
	char	**ceiling;
	size_t	i;

	i = 0;
	floor = ft_split(game->elements.floor_c.rgb, ',');
	ceiling = ft_split(game->elements.ceiling_c.rgb, ',');
	while (i < 3)
	{
		game->elements.ceiling_c.colors[i] = ft_atoi(ceiling[i]);
		game->elements.floor_c.colors[i] = ft_atoi(floor[i]);
		++i;
	}
	free_array(floor);
	free_array(ceiling);
}

int	__run_game(t_game *game, int ac, char **ag)
{
	(void)ac;
	game->path = ag[1];
	init_all(game);
	if (__checker(game))
		return (1);
	__banner();
	set_angle(game);
	set_colors(game);
	if (load_textures(game))
	{
		free_textures(game);
		ft_putendl_fd("Error\nFailed to load textures\n", 2);
		return (2);
	}
	mlx(game);
	mlx_loop(game->mlx.mlx);
	return (0);
}
