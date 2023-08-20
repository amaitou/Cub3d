/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 18:38:31 by amait-ou          #+#    #+#             */
/*   Updated: 2023/08/20 19:17:02 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	__checker(t_game *game)
{
	int	error_for_elements;

	error_for_elements = check_elements(game);
	if (error_for_elements == 1)
	{
		ft_putendl_fd("Error: Invalid Color", 2);
		return (1);
	}
	if (error_for_elements == 2)
	{
		ft_putendl_fd("Error: Invalid Directions", 2);
		return (2);
	}
	return (0);
}
