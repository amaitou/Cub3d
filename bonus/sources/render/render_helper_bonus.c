/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_helper_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 22:22:19 by amait-ou          #+#    #+#             */
/*   Updated: 2023/10/05 18:10:20 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	draw_line_helper(t_game *game, int perspective, int x, int y)
{
	if (perspective)
		mlx_put_pixel(game->mlx.image, round(x), round(y),
			get_rgba(0, 0, 0, 255));
	else
		mlx_put_pixel(game->mlx.image, round(x), round(y),
			get_rgba(255, 26, 26, 255));
}
