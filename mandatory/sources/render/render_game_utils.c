/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 18:24:33 by amait-ou          #+#    #+#             */
/*   Updated: 2023/10/05 17:11:39 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	clear_map(t_game *game)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < WINDOW_WIDTH)
	{
		j = 0;
		while (j < WINDOW_HEIGHT)
		{
			mlx_put_pixel(game->mlx.image, i, j, 0);
			++j;
		}
		++i;
	}
}

void	draw_floor(t_game *game)
{
	size_t	i;
	size_t	j;
	int		*colors;

	colors = game->elements.floor_c.colors;
	i = 0;
	while (i < WINDOW_HEIGHT / 2)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
		{
			mlx_put_pixel(game->mlx.image, j, i, get_rgba(colors[0],
					colors[1], colors[2], 255));
			++j;
		}
		++i;
	}
}

void	draw_ceiling(t_game *game)
{
	size_t	i;
	size_t	j;
	int		*colors;

	colors = game->elements.ceiling_c.colors;
	i = WINDOW_HEIGHT / 2;
	while (i < WINDOW_HEIGHT)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
		{
			mlx_put_pixel(game->mlx.image, j, i, get_rgba(colors[0],
					colors[1], colors[2], 255));
			++j;
		}
		++i;
	}
}
