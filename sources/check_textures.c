/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 00:54:17 by amait-ou          #+#    #+#             */
/*   Updated: 2023/09/21 01:15:50 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int check_path(char *path)
{
    int fd;

    fd = open(path, O_RDONLY);
    if (fd < 0)
        return (1);
    close(fd);
    return (0);
}

int check_directions(t_enums direction, char *s)
{
    if (direction == _NONE || !s)
        return (1);
    return (0);
}