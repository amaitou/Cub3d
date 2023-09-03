/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 17:26:28 by amait-ou          #+#    #+#             */
/*   Updated: 2023/09/03 20:22:25 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	parse_elements(t_game *game)
{
	char	**element;
	int		i;

	i = 0;
	while (game->elements.counter < 6)
	{
		element = ft_split(game->all_items[i], ' ');
		free(game->all_items[i]);
		if (ft_array_len(element) > 1)
		{
			assign_directions(game, element);
			game->elements.counter++;
		}
		else
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
	game->map = (char **)malloc(sizeof(char *) * lines_count(game) + 1);
	if (!game->map)
		return (1);
	while (game->all_items[i])
	{
		game->map[j] = ft_strdup(game->all_items[i]);
		free(game->all_items[i]);
		++i;
		++j;
	}
	game->map[j] = NULL;
	return (0);
}

int	__parser(t_game *game)
{
	init_elements(game);
	if (parse_elements(game))
		return (2);
	if (parse_map(game))
		return (3);
	free(game->all_items);
	return (0);
}
