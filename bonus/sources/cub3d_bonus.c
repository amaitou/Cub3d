/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 15:06:11 by amait-ou          #+#    #+#             */
/*   Updated: 2023/10/05 18:13:32 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

int	main(int ac, char **ag)
{
	t_game	*game;

	if (ac == 2)
	{
		game = (t_game *)malloc(sizeof(t_game));
		if (!game)
		{
			ft_putendl_fd("Error: Failed To Run The Game", 2);
			return (EXIT_FAILURE);
		}
		if (__run_game(game, ac, ag))
			return (EXIT_FAILURE);
	}
	else
	{
		ft_putendl_fd("Error: Invalid Arguments", 2);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
