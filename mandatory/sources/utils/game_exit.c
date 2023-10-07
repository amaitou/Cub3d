/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:21:51 by amait-ou          #+#    #+#             */
/*   Updated: 2023/10/07 16:28:04 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	mlx_exit(t_game *game)
{
	clear_map(game);
	free(game->elements.north.image);
	free(game->elements.south.image);
	free(game->elements.west.image);
	free(game->elements.east.image);
	mlx_delete_image(game->mlx.mlx, game->mlx.image);
	mlx_close_window(game->mlx.mlx);
}
