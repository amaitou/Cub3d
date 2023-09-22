/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 23:36:42 by amait-ou          #+#    #+#             */
/*   Updated: 2023/09/22 02:47:16 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
		game->north++;
	else if (c == 'E')
		game->east++;
	else if (c == 'W')
		game->west++;
	else if (c == 'S')
		game->south++;
	game->player.y = y;
	game->player.x = x;
}

int	__map(t_game *game)
{
	int		i;
	int		j;
	char	**map;

	map = game->map.map;
	__display_map(game);
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
