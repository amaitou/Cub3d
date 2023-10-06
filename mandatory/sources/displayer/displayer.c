/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displayer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 15:08:45 by amait-ou          #+#    #+#             */
/*   Updated: 2023/10/06 16:10:11 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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
	while (game->map.map[i])
	{
		ft_printf("%s\n", game->map.map[i]);
		++i;
	}
}

void	__display_rays(t_game *game)
{
	size_t	i;

	i = 0;
	while (i < WINDOW_WIDTH)
	{
		ft_printf("[x] -> %.2f, [y] -> %.2f\n",
			game->rays[i].h_wall_hit_x, game->rays[i].h_wall_hit_y);
		++i;
	}
}
