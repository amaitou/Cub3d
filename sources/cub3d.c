/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 15:06:11 by amait-ou          #+#    #+#             */
/*   Updated: 2023/09/22 02:40:50 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
		{
			// system("leaks cub3D");
			return (EXIT_FAILURE);
		}
		__display_elements(game);
		printf("y -> %.2f\n", game->player.y);
		printf("x -> %.2f", game->player.x);
		// system("leaks cub3D");
	}
	else
		ft_putendl_fd("Error: Invalid Arguments", 2);
	return (EXIT_SUCCESS);
}
