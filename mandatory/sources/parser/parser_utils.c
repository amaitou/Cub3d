/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 15:17:02 by amait-ou          #+#    #+#             */
/*   Updated: 2023/10/03 03:00:50 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	assign_color(t_game *game, char **element)
{
	if (!ft_strcmp(game->temp, "F"))
	{
		game->elements.floor_c.type = _COLOR_F;
		game->elements.floor_c.surface = ft_strdup(game->temp);
		game->elements.floor_c.rgb = ft_strdup(element[1]);
		return ;
	}
	if (!ft_strcmp(game->temp, "C"))
	{
		game->elements.ceiling_c.type = _COLOR_C;
		game->elements.ceiling_c.surface = ft_strdup(game->temp);
		game->elements.ceiling_c.rgb = ft_strdup(element[1]);
		return ;
	}
}

void	assign_directions(t_game *game, char **element)
{
	game->temp = ft_strtrim(element[0], " \t");
	if (!ft_strcmp("NO", game->temp))
	{
		game->elements.north.direction = _NORTH;
		game->elements.north.texture = ft_strdup(element[1]);
	}
	else if (!ft_strcmp("SO", game->temp))
	{
		game->elements.south.direction = _SOUTH;
		game->elements.south.texture = ft_strdup(element[1]);
	}
	else if (!ft_strcmp("EA", game->temp))
	{
		game->elements.east.direction = _EAST;
		game->elements.east.texture = ft_strdup(element[1]);
	}
	else if (!ft_strcmp("WE", game->temp))
	{
		game->elements.west.direction = _WEST;
		game->elements.west.texture = ft_strdup(element[1]);
	}
	else
		assign_color(game, element);
	free(game->temp);
}

int	lines_count(t_game *game)
{
	int	i;
	int	j;

	i = game->elements.counter;
	j = i;
	while (game->all_items[i])
		++i;
	game->map.map_len = i - j;
	return (i);
}

int	check_directions(t_enums direction, char *s)
{
	if (direction == _NONE || s == NULL)
		return (1);
	return (0);
}
