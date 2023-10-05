/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 19:08:37 by amait-ou          #+#    #+#             */
/*   Updated: 2023/10/05 17:20:27 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	render_game(t_game *game)
{
	clear_map(game);
	draw_ceiling(game);
	draw_floor(game);
	cast_rays(game);
	projection_plan(game);
}
