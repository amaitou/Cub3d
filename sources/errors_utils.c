/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 19:27:18 by amait-ou          #+#    #+#             */
/*   Updated: 2023/09/17 23:41:46 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	error_helper(t_game *game, char d, int x, int y)
{
	if (d == 'N')
	{
		game->north++;
		game->player.x = x * TILE + (TILE / 2);
		game->player.y = y * TILE + (TILE / 2);
	}
	if (d == 'E')
	{
		game->east++;
		game->player.x = x * TILE + (TILE / 2);
		game->player.y = y * TILE + (TILE / 2);
	}
	if (d == 'W')
	{
		game->west++;
		game->player.x = x * TILE + (TILE / 2);
		game->player.y = y * TILE + (TILE / 2);
	}
	if (d == 'S')
	{
		game->south++;
		game->player.x = x * TILE + (TILE / 2);
		game->player.y = y * TILE + (TILE / 2);
	}
}

int	check_map_helper(t_game *game, int i, int j)
{
	if (game->map.map[i][j] == 'N' || game->map.map[i][j] == 'W'
			|| game->map.map[i][j] == 'S' || game->map.map[i][j] == 'E')
		error_helper(game, game->map.map[i][j], j, i);
	else if (!(ft_strchr("\t 01", game->map.map[i][j])))
	{
		ft_putendl_fd("Error: Invalid Character Within The Map", 2);
		return (1);
	}
	return (0);
}

int	starts_with_one(char *s)
{
	while ((*s == ' ' || *s == '\t') && *s)
		++s;
	if (*s && *s == '1')
		return (0);
	return (1);
}

int	ends_with_one(char *s)
{
	int	b;

	b = 0;
	while (*s)
	{
		if (*s == '0')
			b = 0;
		else if (*s == '1')
			b = 1;
		++s;
	}
	if (b)
		return (0);
	return (1);
}

int	all_ones(char *s, int index)
{
	while (s[index])
	{
		if (s[index] != '1')
			return (1);
		++index;
	}
	return (0);
}

int	check_spaces(t_game *game, int i)
{
	char	*line;
	int		j;

	line = game->map.map[i];
	j = 0;
	while (line[j])
	{
		if (line[j] == ' ' || line[j] == '\t')
		{
			if (game->map.map[i + 1] != NULL)
			{
				if (all_ones(game->map.map[i + 1], j))
					return (1);
			}
		}
		++j;
	}
	return (0);
}
