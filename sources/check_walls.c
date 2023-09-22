/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 21:54:54 by amait-ou          #+#    #+#             */
/*   Updated: 2023/09/22 22:14:12 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	wall_up_down(t_game *game)
{
	int		len;
	char	*first;
	char	*last;

	len = 0;
	first = game->map.map[0];
	while (*first)
	{
		if (*first != '1')
			return (0);
		++first;
	}
	last = game->map.map[ft_array_len(game->map.map) - 1];
	while (*last)
	{
		if (*last != '1')
			return (1);
		++last;
	}
	return (0);
}

static int	wall_middle(t_game *game)
{
	int		len;
	int		i;
	int		j;
	size_t	l;

	len = ft_array_len(game->map.map);
	i = 0;
	while (game->map.map[0][i] && game->map.map[len - 1][i])
	{
		if (!(game->map.map[0][i] == '1' && game->map.map[len - 1][i] == '1'))
			return (1);
		++i;
	}
	j = 1;
	while (j < len - 1)
	{
		l = ft_strlen(game->map.map[j]);
		if (!(game->map.map[j][0] == '1' && game->map.map[j][l - 1] == '1'))
			return (1);
		++j;
	}
	return (0);
}

int	__walls(t_game *game)
{
	if (wall_up_down(game))
		return (1);
	if (wall_middle(game))
		return (2);
	return (0);
}
