/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_spaces_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhalil- <ykhalil-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 21:01:14 by ykhalil-          #+#    #+#             */
/*   Updated: 2023/10/06 11:22:15 by ykhalil-         ###   ########.fr       */
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
