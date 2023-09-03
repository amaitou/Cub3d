/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 18:38:31 by amait-ou          #+#    #+#             */
/*   Updated: 2023/09/03 15:51:30 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	__checker(t_game *game)
{
	if (check_reader(game))
		return (1);
	if (check_parser(game))
		return (2);
	if (check_elements(game))
		return (3);
	if (check_map(game))
		return (4);
	if (check_walls(game))
		return (5);
	if (map_closed(game))
		return (6);
	if (check_rgb(game))
		return (7);
	return (0);
}
