/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 23:36:42 by amait-ou          #+#    #+#             */
/*   Updated: 2023/10/05 16:49:15 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	check_for_chars(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (!ft_strchr("NEWS \t01", s[i]))
			return (1);
		++i;
	}
	return (0);
}

static void	check_for_player(t_game *game, char c, int y, int x)
{
	if (c == 'N')
	{
		game->north++;
		game->player.direction = 'N';
	}
	else if (c == 'E')
	{
		game->east++;
		game->player.direction = 'E';
	}
	else if (c == 'W')
	{
		game->west++;
		game->player.direction = 'W';
	}
	else if (c == 'S')
	{
		game->south++;
		game->player.direction = 'S';
	}
	game->player.y = y * TILE + (TILE / 2);
	game->player.x = x * TILE + (TILE / 2);
}

int	__map(t_game *game)
{
	int		i;
	int		j;
	char	**map;

	map = game->map.map;
	i = 0;
	while (map[i])
	{
		if (check_for_chars(map[i]))
			return (1);
		j = 0;
		while (map[i][j])
		{
			if (ft_strchr("NEWS", map[i][j]))
				check_for_player(game, map[i][j], i, j);
			++j;
		}
		++i;
	}
	if (!(game->north + game->west + game->south + game->east == 1))
		return (2);
	return (0);
}
