/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 04:28:00 by amait-ou          #+#    #+#             */
/*   Updated: 2023/09/21 19:48:06 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_parser(t_game *game)
{
	int	parser_return_value;

	parser_return_value = __parser(game);
	if (check_map_and_elements(parser_return_value))
		return (1);
	if (check_textures(game))
		return (2);
	return (0);
}

int	check_reader(t_game *game)
{
	int	reader_return_value;

	reader_return_value = __reader(game);
	if (reader_return_value == 1)
	{
		ft_putendl_fd("Error: Failed to open the map file", 2);
		return (1);
	}
	if (reader_return_value == 2)
	{
		ft_putendl_fd("Error: File is empty", 2);
		return (2);
	}
	if (reader_return_value == 3)
	{
		ft_putendl_fd("Error: Map has consecutive new lines", 2);
		return (3);
	}
	return (0);
}

int	check_rgb(t_game *game)
{
	int	rgb_return_value;

	rgb_return_value = __rgb(game);
	if (rgb_return_value == 1)
	{
		ft_putendl_fd("Error: Invalid RGB format", 2);
		return (1);
	}
	if (rgb_return_value == 2)
	{
		ft_putendl_fd("Error: RGB contains weird chars", 2);
		return (2);
	}
	if (rgb_return_value == 3)
	{
		ft_putendl_fd("Error: RGB is out of range", 2);
		return (3);
	}
	if (rgb_return_value == 5)
	{
		ft_putendl_fd("Error: Name of surface should be either F or C", 2);
		return (5);
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
	return (0);
}
