/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 21:54:54 by amait-ou          #+#    #+#             */
/*   Updated: 2023/09/23 00:29:41 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	wall_up_down(t_game *game)
{
	char	*first;
	char	*last;

	first = game->map.map[0];
	while (*first)
	{
		if (*first != '1')
			return (1);
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

int	wall_start_end(char *s)
{
	size_t	i;
	int		a;
	int		b;

	i = 0;
	b = 0;
	a = 0;
	while (s[i] && !a)
	{
		while (s[i] && (s[i] == ' ' || s[i] == '\t'))
			++i;
		if (s[i] && s[i] == '1')
			a = 1;
	}
	while (s[i])
	{
		if (s[i] == '1')
			b = 1;
		else if (s[i] == '0')
			b = 0;
		++i;
	}
	return (!a || !b);
}

static int	wall_middle(t_game *game)
{
	size_t	start;
	size_t	end;

	start = 1;
	end = ft_array_len(game->map.map) - 1;
	while (start < end)
	{
		if (wall_start_end(game->map.map[start]))
			return (1);
		++start;
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
