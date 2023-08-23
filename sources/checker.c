/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 18:38:31 by amait-ou          #+#    #+#             */
/*   Updated: 2023/08/22 23:53:48 by amait-ou         ###   ########.fr       */
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
	return (0);
}
