/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 17:26:28 by amait-ou          #+#    #+#             */
/*   Updated: 2023/08/20 17:00:51 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	parse_elements(t_game *game)
{
	char	**element;
	int		i;

	i = 0;
	while (game->elements->counter < 6)
	{
		element = ft_split(game->all_items[i], ' ');
		free(game->all_items[i]);
		if (ft_array_len(element) > 1)
		{
			assign_directions(game, element);
			game->elements->counter++;
		}
		else
			return (1);
		free_array(element);
		++i;
	}
	return (0);
}

int	parse_map(t_game *game)
{
	int	j;
	int	i;

	j = 0;
	i = game->elements->counter;
	game->map = (char **)malloc(sizeof(char *) * lines_count(game) + 1);
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
	game->elements = (t_elements *)malloc(sizeof(t_elements));
	init_elements(game);
	if (!game->elements)
	{
		ft_putendl_fd("Error: Failed to run the game", 2);
		return (1);
	}
	if (parse_elements(game))
	{
		ft_putendl_fd("Error: Failed Parse Map Elements", 2);
		return (1);
	}
	parse_map(game);
	free(game->all_items);
	return (0);
}
