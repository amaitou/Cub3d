/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 18:31:27 by amait-ou          #+#    #+#             */
/*   Updated: 2023/08/20 19:18:15 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_elements(t_game *game)
{
	t_elements	*elements;

	elements = game->elements;
	if (elements->ceiling_c.type == _NONE || elements->floor_c.type == _NONE)
		return (1);
	if (!elements->east.texture || !elements->north.texture
		|| !elements->west.texture || !elements->south.texture)
		return (2);
	return (0);
}
