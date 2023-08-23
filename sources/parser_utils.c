/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 15:17:02 by amait-ou          #+#    #+#             */
/*   Updated: 2023/08/23 15:33:01 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_elements(t_game *game)
{
	game->elements.ceiling_c.type = _NONE;
	game->elements.ceiling_c.surface = NULL;
	game->elements.ceiling_c.rgb = NULL;
	game->elements.floor_c.type = _NONE;
	game->elements.floor_c.surface = NULL;
	game->elements.floor_c.rgb = NULL;
	game->elements.north.direction = _NONE;
	game->elements.north.texture = NULL;
	game->elements.south.direction = _NONE;
	game->elements.south.texture = NULL;
	game->elements.east.direction = _NONE;
	game->elements.east.texture = NULL;
	game->elements.west.direction = _NONE;
	game->elements.west.texture = NULL;
	game->elements.counter = 0;
}

void	assign_color(t_game *game, char **element)
{
	if (!ft_strcmp("F", element[0]))
	{
		game->elements.floor_c.type = _COLOR_C;
		game->elements.floor_c.surface = ft_strdup(element[0]);
		game->elements.floor_c.rgb = ft_strdup(element[1]);
	}
	else if (!ft_strcmp("C", element[0]))
	{
		game->elements.ceiling_c.type = _COLOR_C;
		game->elements.ceiling_c.surface = ft_strdup(element[0]);
		game->elements.ceiling_c.rgb = ft_strdup(element[1]);
	}
}

void	assign_directions(t_game *game, char **element)
{
	if (!ft_strcmp("NO", element[0]))
	{
		game->elements.north.direction = _NORTH;
		game->elements.north.texture = ft_strdup(element[1]);
	}
	else if (!ft_strcmp("SO", element[0]))
	{
		game->elements.south.direction = _SOUTH;
		game->elements.south.texture = ft_strdup(element[1]);
	}
	else if (!ft_strcmp("EA", element[0]))
	{
		game->elements.east.direction = _EAST;
		game->elements.east.texture = ft_strdup(element[1]);
	}
	else if (!ft_strcmp("WE", element[0]))
	{
		game->elements.west.direction = _WEST;
		game->elements.west.texture = ft_strdup(element[1]);
	}
	else
		assign_color(game, element);
}

int	lines_count(t_game *game)
{
	int	i;

	i = game->elements.counter;
	while (game->all_items[i])
		++i;
	game->len = i;
	return (i);
}
