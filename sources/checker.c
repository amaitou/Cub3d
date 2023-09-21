/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 01:16:56 by amait-ou          #+#    #+#             */
/*   Updated: 2023/09/21 01:26:36 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int check_parser(t_game *game)
{
    int parser_return_value;

    parser_return_value = __parser(game);
    if (parser_return_value == 1)
    {
        ft_putendl_fd("Error: There are missing or additional params", 2);
        return (1);
    }
    else if (parser_return_value == 2)
    {
        ft_putendl_fd("Error: Failed to allocate the map size", 2);
        return (1);
    }
    return (0);
}