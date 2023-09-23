/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 21:54:54 by amait-ou          #+#    #+#             */
/*   Updated: 2023/09/23 21:38:16 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	wall_up_down(char *s)
{
	char	*temp;
	size_t	i;

	temp = ft_strtrim(s, " ");
	i = 0;
	while (temp[i])
	{
		if (temp[i] != '1' && temp[i] != ' ')
		{
			free(temp);
			return (1);
		}
		++i;
	}
	free(temp);
	return (0);
}

static int	wall_middle_helper(char *s)
{
	char	*temp;
	size_t	i;
	int		boolean;

	temp = ft_strtrim(s, " ");
	i = 0;
	boolean = 0;
	if (temp[i] != '1')
		return (1);
	++i;
	while (temp[i])
	{
		if (temp[i] == '1')
			boolean = 1;
		if (temp[i] == '0')
			boolean = 0;
		++i;
	}
	if (!boolean)
		return (1);
	return (0);
}

static int	wall_middle(char **map)
{
	size_t	start;
	size_t	end;

	start = 1;
	end = ft_array_len(map) - 1;
	while (start < end)
	{
		if (wall_middle_helper(map[start]))
			return (1);
		++start;
	}
	return (0);
}

int	__walls(t_game *game)
{
	if (wall_up_down(game->map.map[0])
		|| wall_up_down(game->map.map[ft_array_len(game->map.map) - 1]))
		return (1);
	if (wall_middle(game->map.map))
		return (1);
	if (check_spaces(game))
		return (2);
	return (0);
}
