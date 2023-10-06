/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhalil- <ykhalil-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 04:28:00 by ykhalil-          #+#    #+#             */
/*   Updated: 2023/10/06 11:28:31 by ykhalil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	check_parser(t_game *game)
{
	int	parser_return_value;

	parser_return_value = __parser(game);
	if (check_map_and_elements(parser_return_value))
		return (1);
	if (check_textures(game))
		return (2);
	return (0);
}

static int	check_reader(t_game *game)
{
	int	reader_return_value;

	reader_return_value = __reader(game);
	if (reader_return_value == 1)
	{
		ft_putendl_fd("Error\nFailed to open the map file", 2);
		return (1);
	}
	if (reader_return_value == 2)
	{
		ft_putendl_fd("Error\nFile is empty", 2);
		return (2);
	}
	if (reader_return_value == 3)
	{
		ft_putendl_fd("Error\nMap has consecutive new lines", 2);
		return (3);
	}
	if (reader_return_value == 4)
	{
		ft_putendl_fd("Error\nInvalid path name", 2);
		return (4);
	}
	return (0);
}

static int	check_rgb(t_game *game)
{
	int	rgb_return_value;

	rgb_return_value = __rgb(game);
	if (rgb_return_value == 1)
	{
		ft_putendl_fd("Error\nInvalid RGB format", 2);
		return (1);
	}
	if (rgb_return_value == 2)
	{
		ft_putendl_fd("Error\nRGB contains weird chars", 2);
		return (2);
	}
	if (rgb_return_value == 3)
	{
		ft_putendl_fd("Error\nRGB is out of range", 2);
		return (3);
	}
	if (rgb_return_value == 5)
	{
		ft_putendl_fd("Error\nName of surface should be either F or C", 2);
		return (5);
	}
	return (0);
}

static int	check_map(t_game *game)
{
	int	map_return_value;
	int	wall_return_value;

	map_return_value = __map(game);
	if (map_return_value == 1)
	{
		ft_putendl_fd("Error\nMap contains invalid chars", 2);
		return (1);
	}
	if (map_return_value == 2)
	{
		ft_putendl_fd("Error\nInvalid player position", 2);
		return (2);
	}
	wall_return_value = __walls(game);
	if (wall_return_value)
	{
		if (wall_return_value == 1)
			ft_putendl_fd("Error\nmap must be surrounded by walls", 2);
		if (wall_return_value == 2)
			ft_putendl_fd("Error\nplayer cannot moves in spaces", 2);
		return (1);
	}
	return (0);
}

int	__checker(t_game *game)
{
	if (check_reader(game))
		return (1);
	if (check_parser(game))
		return (2);
	if (check_rgb(game))
		return (3);
	if (check_map(game))
		return (4);
	return (0);
}
