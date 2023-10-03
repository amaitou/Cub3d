/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 20:34:15 by amait-ou          #+#    #+#             */
/*   Updated: 2023/10/03 20:42:27 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	load_textures(t_game *game)
{
	game->elements.north.image = mlx_load_png(game->elements.north.texture);
	if (!game->elements.north.image)
		return (1);
	game->elements.south.image = mlx_load_png(game->elements.south.texture);
	if (!game->elements.south.image)
		return (1);
	game->elements.west.image = mlx_load_png(game->elements.west.texture);
	if (!game->elements.west.image)
		return (1);
	game->elements.east.image = mlx_load_png(game->elements.east.texture);
	if (!game->elements.east.image)
		return (1);
	return (0);
}
