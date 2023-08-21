/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 19:27:18 by amait-ou          #+#    #+#             */
/*   Updated: 2023/08/21 19:43:59 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	error_helper(t_game *game, char d, int x, int y)
{
	if (d == 'N')
	{
		game->north++;
		game->player.x = x;
		game->player.y = y;
	}
	if (d == 'E')
	{
		game->east++;
		game->player.x = x;
		game->player.y = y;
	}
	if (d == 'W')
	{
		game->west++;
		game->player.x = x;
		game->player.y = y;
	}
	if (d == 'S')
	{
		game->south++;
		game->player.x = x;
		game->player.y = y;
	}
}
