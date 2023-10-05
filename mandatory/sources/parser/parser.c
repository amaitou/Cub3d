/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 17:26:28 by amait-ou          #+#    #+#             */
/*   Updated: 2023/10/03 03:00:55 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	alter(char *s)
{
	while ((*s == ' ' || *s == '\t') && *s)
		++s;
	while (*s)
	{
		if (*s == ' ' || *s == '\t')
		{
			*s = '\n';
			return ;
		}
		++s;
	}
}

static int	parse_elements(t_game *game)
{
	char	**element;
	int		i;

	i = 0;
	while (game->elements.counter < 6)
	{
		alter(game->all_items[i]);
		element = ft_split(game->all_items[i], '\n');
		free(game->all_items[i]);
		if (ft_array_len(element) == 2)
		{
			assign_directions(game, element);
			game->elements.counter++;
		}
		else if (ft_array_len(element) < 2 || ft_array_len(element) > 2)
		{
			free_array(element);
			return (1);
		}
		free_array(element);
		++i;
	}
	return (0);
}

static int	parse_map(t_game *game)
{
	int	j;
	int	i;

	j = 0;
	i = game->elements.counter;
	game->map.map = (char **)malloc(sizeof(char *) * lines_count(game) + 1);
	if (!game->map.map)
		return (1);
	if (game->all_items[i])
	{
		while (game->all_items[i])
		{
			game->map.map[j] = ft_strdup(game->all_items[i]);
			if (ft_strlen(game->all_items[i]) > game->map.width)
				game->map.width = ft_strlen(game->all_items[i]);
			free(game->all_items[i]);
			++i;
			++j;
		}
		game->map.map[j] = NULL;
		game->map.height = j;
	}
	else
		return (3);
	return (0);
}

int	__parser(t_game *game)
{
	int	_parse_elements;
	int	_parse_map;

	_parse_elements = parse_elements(game);
	if (_parse_elements)
		return (_parse_elements);
	_parse_map = parse_map(game);
	if (_parse_map)
		return (_parse_map);
	return (0);
}
