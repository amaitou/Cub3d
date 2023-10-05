/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leaks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 15:52:06 by amait-ou          #+#    #+#             */
/*   Updated: 2023/10/05 04:55:07 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	free_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		++i;
	}
	free(arr);
}

void	free_textures(t_game *game)
{
	if (!game->elements.north.image)
		return ;
	else if (!game->elements.south.image)
		free(game->elements.north.image);
	else if (!game->elements.west.image)
	{
		free(game->elements.north.image);
		free(game->elements.south.image);
	}
	else if (!game->elements.east.image)
	{
		free(game->elements.north.image);
		free(game->elements.south.image);
		free(game->elements.west.image);
	}
}
