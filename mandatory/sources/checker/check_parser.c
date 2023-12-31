/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhalil- <ykhalil-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 01:16:56 by ykhalil-          #+#    #+#             */
/*   Updated: 2023/10/06 11:28:04 by ykhalil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_map_and_elements(int parser_return_value)
{
	if (parser_return_value == 1)
	{
		ft_putendl_fd("Error\nThere are missing or additional params", 2);
		return (1);
	}
	else if (parser_return_value == 2)
	{
		ft_putendl_fd("Error\nFailed to allocate the map size", 2);
		return (1);
	}
	else if (parser_return_value == 3)
	{
		ft_putendl_fd("Error\nMap is missing", 2);
		return (1);
	}
	return (0);
}

int	check_textures(t_game *game)
{
	t_elements	*element;

	element = &game->elements;
	if (check_directions(element->east.direction, element->east.texture)
		|| check_directions(element->north.direction, element->north.texture)
		|| check_directions(element->west.direction, element->west.texture)
		|| check_directions(element->south.direction, element->south.texture))
	{
		ft_putendl_fd("Error\nInvalid Direction", 2);
		return (1);
	}
	return (0);
}
