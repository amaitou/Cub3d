/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 15:06:11 by amait-ou          #+#    #+#             */
/*   Updated: 2023/08/21 19:26:32 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_directions(t_game *game)
{
	game->east = 0;
	game->north = 0;
	game->west = 0;
	game->south = 0;
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
		init_directions(game);
		if (__checker(game))
		{
			system("leaks cub3D");
			return (0);
		}
		__display_elements(game);
		__display_map(game);
		system("leaks cub3D");
	}
	else
		ft_putendl_fd("Error: Invalid Arguments", 2);
	return (0);
}
