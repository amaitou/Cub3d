/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_closed.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 15:34:53 by amait-ou          #+#    #+#             */
/*   Updated: 2023/08/23 17:36:16 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	check_zero_with_space(char *s, size_t *index)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '0' && s[i + 1] && (s[i + 1] == ' ' || s[i + 1] == '\t'))
		{
			*index = i;
			return (1);
		}
		++i;
	}
	return (0);
}

static int	check_index_with_space(char *s, size_t index)
{
	if (s[index])
	{
		if (s[index] == ' ' || s[index] == '\t')
			return (1);
	}
	return (0);
}

int	map_closed(t_game *game)
{
	char		*current;
	char		*next;
	int			i;
	size_t		index;

	i = 0;
	while (game->map[i])
	{
		current = game->map[i];
		if (check_zero_with_space(current, &index))
		{
			if (game->map[i + 1])
			{
				next = game->map[i + 1];
				if (check_index_with_space(next, index)
					|| index >= ft_strlen(next))
				{
					ft_putendl_fd("Error: Map Is Not Surrounded By Walls", 2);
					return (1);
				}
			}
		}
		++i;
	}
	return (0);
}
