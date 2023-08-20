/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 15:00:09 by amait-ou          #+#    #+#             */
/*   Updated: 2023/08/20 20:05:28 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	__reader(t_game *game)
{
	char	*line;

	game->fd = open(game->path, O_RDONLY);
	if (game->fd < 0)
		return (1);
	line = get_next_line(game->fd);
	if (!line)
		return (2);
	game->lines = NULL;
	while (line)
	{
		game->lines = ft_strjoin(game->lines, line);
		line = get_next_line(game->fd);
	}
	game->all_items = ft_split(game->lines, '\n');
	free(line);
	return (0);
}
