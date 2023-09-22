/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 21:54:54 by amait-ou          #+#    #+#             */
/*   Updated: 2023/09/22 22:43:53 by amait-ou         ###   ########.fr       */
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

int	wall_start_end(char *s)
{
	size_t	i;
	size_t	j;

	j = 0;
	while (s[j])
	{
		while (s[j] && (s[j] == ' ' || s[j] == '\t'))
			++j;
		if (s[j])
		{
			if (s[j] != '1')
				return (1);
			i = ft_strlen(s) - 1;
			while (i >= 0)
			{
				while (s[i] && (s[i] == ' ' || s[i] == '\t'))
					--i;
				if (s[i] != '1')
					return (1);
			}
		}
		++j;
	}
	return (0);
}

static int	wall_middle(t_game *game)
{
	size_t	start;
	size_t	end;

	start = 1;
	printf("[.] %lu, ", start);
	end = ft_array_len(game->map.map) - 1;
	printf("[.] %lu, ", end);
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
