/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 18:24:33 by amait-ou          #+#    #+#             */
/*   Updated: 2023/10/03 22:24:08 by amait-ou         ###   ########.fr       */
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

void	draw_rays(t_game *game)
{
	int	i;

	i = 0;
	while (i < WINDOW_WIDTH)
	{
		if (game->rays[i].was_hit_vertical)
			draw_line(game,
				game->rays[i].wall_hit_x, game->rays[i].wall_hit_y, 0);
		else
			draw_line(game,
				game->rays[i].wall_hit_x, game->rays[i].wall_hit_y, 1);
		++i;
	}
}

void	draw_line(t_game *game, float x1, float y1, int perspective)
{
	int		i;
	float	x;
	float	y;

	game->dda.dx = x1 - game->player.x;
	game->dda.dy = y1 - game->player.y;
	if (abs(game->dda.dx) > abs(game->dda.dy))
		game->dda.steps = abs(game->dda.dx);
	else
		game->dda.steps = abs(game->dda.dy);
	game->dda.xinc = game->dda.dx / (float)game->dda.steps;
	game->dda.yinc = game->dda.dy / (float)game->dda.steps;
	x = game->player.x;
	y = game->player.y;
	i = 0;
	while (i <= game->dda.steps)
	{
		draw_line_helper(game, perspective, x, y);
		x += game->dda.xinc;
		y += game->dda.yinc;
		++i;
	}
}
