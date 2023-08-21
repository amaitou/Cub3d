/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 19:27:18 by amait-ou          #+#    #+#             */
/*   Updated: 2023/08/21 22:14:44 by amait-ou         ###   ########.fr       */
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

int	check_map_helper(t_game *game, int i, int j)
{
	if (game->map[i][j] == 'N' || game->map[i][j] == 'W' 
			|| game->map[i][j] == 'S' || game->map[i][j] == 'E')
		error_helper(game, game->map[i][j], j, i);
	else if (!(ft_strchr("\t 01", game->map[i][j])))
		return (1);
	return (0);
}
