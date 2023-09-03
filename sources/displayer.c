/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displayer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 15:08:45 by amait-ou          #+#    #+#             */
/*   Updated: 2023/09/03 20:21:08 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	__display_items(t_game *game)
{
	int	i;

	i = 0;
	while (game->all_items[i])
	{
		ft_printf("%s\n", game->all_items[i]);
		++i;
	}
}

static void	display_directions(t_enums direction)
{
	if (direction == _NORTH)
		ft_putendl_fd("north", 2);
	else if (direction == _SOUTH)
		ft_putendl_fd("south", 2);
	else if (direction == _EAST)
		ft_putendl_fd("east", 2);
	else if (direction == _WEST)
		ft_putendl_fd("west", 2);
	else if (direction == _COLOR_C)
		ft_putendl_fd("ceiling", 2);
	else if (direction == _COLOR_F)
		ft_putendl_fd("floor", 2);
	else
		ft_putendl_fd("null", 2);
}

void	__display_elements(t_game *game)
{
	ft_printf("north -> %s, ", game->elements.north.texture);
	display_directions(game->elements.north.direction);
	ft_printf("south -> %s, ", game->elements.south.texture);
	display_directions(game->elements.south.direction);
	ft_printf("west -> %s, ", game->elements.west.texture);
	display_directions(game->elements.west.direction);
	ft_printf("east -> %s, ", game->elements.east.texture);
	display_directions(game->elements.east.direction);
	ft_printf("floor -> %s, %s, ", game->elements.floor_c.surface,
		game->elements.floor_c.rgb);
	display_directions(game->elements.floor_c.type);
	ft_printf("ceiling -> %s, %s, ", game->elements.ceiling_c.surface,
		game->elements.ceiling_c.rgb);
	display_directions(game->elements.ceiling_c.type);
}

void	__display_map(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		ft_printf("%s\n", game->map[i]);
		++i;
	}
}
