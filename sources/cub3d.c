/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 15:06:11 by amait-ou          #+#    #+#             */
/*   Updated: 2023/08/20 16:41:36 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int ac, char **ag)
{
	t_game	*game;

	if (ac == 2)
	{
		game = (t_game *)malloc(sizeof(t_game));
		game->path = ag[1];
		if (!game)
		{
			ft_putendl_fd("Error: Failed To Run The Game", 2);
			return (0);
		}
		__reader(game);
		__parser(game);
		__display_elements(game);
		__display_map(game);
		system("leaks cub3D");
	}
}
