/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhalil- <ykhalil-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 21:54:54 by ykhalil-          #+#    #+#             */
/*   Updated: 2023/10/06 11:22:23 by ykhalil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

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

static void	wall_helper(char *temp, int i, int *boolean)
{
	if (temp[i] == '1')
		*boolean = 1;
	if (temp[i] == '0')
		*boolean = 0;
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
	{
		free(temp);
		return (1);
	}
	++i;
	while (temp[i])
	{
		wall_helper(temp, i, &boolean);
		++i;
	}
	if (!boolean)
	{
		free(temp);
		return (1);
	}
	free(temp);
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
