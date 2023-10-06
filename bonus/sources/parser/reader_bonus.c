/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhalil- <ykhalil-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 15:00:09 by ykhalil-          #+#    #+#             */
/*   Updated: 2023/10/06 11:22:58 by ykhalil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

static int	check_path(char *s)
{
	char	**p;
	int		i;

	p = ft_split(s, '.');
	i = ft_array_len(p);
	if (i >= 2)
	{
		if (ft_strcmp(p[i - 1], "cub") == 0)
		{
			free_array(p);
			return (0);
		}
	}
	free_array(p);
	return (1);
}

int	__reader(t_game *game)
{
	char	*line;

	if (check_path(game->path))
		return (4);
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
	if (check_consecutive_new_lines(game->lines))
		return (3);
	game->all_items = ft_split(game->lines, '\n');
	free(line);
	return (0);
}
