/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 23:36:42 by amait-ou          #+#    #+#             */
/*   Updated: 2023/09/21 23:40:58 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int check_for_chars(char *s)
{
    while (*s)
    {
        if (*s != '1' || *s != ' ' || *s != '0' || !ft_strchr("NEWS", *s))
            return (1);
        ++s;
    }
    return (0);
}

int __map(t_game *game)
{
    return (0);
}