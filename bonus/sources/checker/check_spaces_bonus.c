/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_spaces_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 21:01:14 by amait-ou          #+#    #+#             */
/*   Updated: 2023/10/05 18:07:42 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

static int	shared_space(char **map, int y, int x)
{
	if (ft_strchr("N0", map[y][x]) && map[y][x - 1]
		&& ft_strchr(" \t", map[y][x - 1]))
		return (1);
	if (ft_strchr("N0", map[y][x]) && map[y][x + 1]
		&& ft_strchr(" \t", map[y][x + 1]))
		return (1);
	if (ft_strchr("N0", map[y][x]) && map[y - 1][x]
		&& ft_strchr(" \t", map[y - 1][x]))
		return (1);
	if (ft_strchr("N0", map[y][x]) && map[y + 1][x]
		&& ft_strchr(" \t", map[y + 1][x]))
		return (1);
	return (0);
}

int	check_spaces(t_game *game)
{
	char		**map;
	int			y;
	size_t		x;

	map = game->map.map;
	y = 1;
	while (y < ft_array_len(map) - 1)
	{
		x = 0;
		while (map[y][x])
		{
			if (ft_strchr("N0", map[y][x]) && shared_space(map, y, x))
				return (1);
			++x;
		}
		++y;
	}
	return (0);
}
