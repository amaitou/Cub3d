/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 20:50:39 by amait-ou          #+#    #+#             */
/*   Updated: 2023/08/21 19:58:52 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_reader(t_game *game)
{
	int	error_for_reader;

	error_for_reader = __reader(game);
	if (error_for_reader == 1)
	{
		ft_putendl_fd("Error: Failed To Read Map File", 2);
		return (1);
	}
	if (error_for_reader == 2)
	{
		ft_putendl_fd("Error: File is Empty", 2);
		return (2);
	}
	return (0);
}

int	check_parser(t_game *game)
{
	int	error_for_parser;

	error_for_parser = __parser(game);
	if (error_for_parser == 1)
	{
		ft_putendl_fd("Error: Failed To Run The Game", 2);
		return (1);
	}
	if (error_for_parser == 2)
	{
		ft_putendl_fd("Error: Invalid Map Elements", 2);
		return (2);
	}
	if (error_for_parser == 3)
	{
		ft_putendl_fd("Error: Failed To Parse Map Lines", 2);
		return (2);
	}
	return (0);
}

int	check_elements(t_game *game)
{
	t_elements	*elements;

	elements = &game->elements;
	if (elements->ceiling_c.type == _NONE || elements->floor_c.type == _NONE)
	{
		ft_putendl_fd("Error: Invalid Colors", 2);
		return (1);
	}
	if (!elements->east.texture || !elements->north.texture
		|| !elements->west.texture || !elements->south.texture)
	{
		ft_putendl_fd("Error: Invalid Directions", 2);
		return (2);
	}
	return (0);
}

int	check_map(t_game *game)
{
	int	i;
	int	j;

	game->player.x = 0;
	game->player.y = 0;
	i = -1;
	while (game->map[++i])
	{
		j = 0;
		while (game->map[i][j] == ' ' || game->map[i][j] == '\t')
			++j;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'N' || game->map[i][j] == 'W' 
					|| game->map[i][j] == 'S' || game->map[i][j] == 'E')
				error_helper(game, game->map[i][j], j, i);
			++j;
		}
	}
	if (!(game->east + game->north + game->west + game->south == 1))
	{
		ft_putendl_fd("Error: There Is No Only One Position For The Player", 2);
		return (1);
	}
	return (0);
}
