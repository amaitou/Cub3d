/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:45:11 by amait-ou          #+#    #+#             */
/*   Updated: 2023/09/13 20:45:11 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	_abs(int v)
{
	if (v < 0)
		return (v * (-1));
	return (v);
}

// static int	_steps(int dx, int dy)
// {
// 	if (_abs(dx) > _abs(dy))
// 		return (_abs(dx));
// 	return (_abs(dy));
// }

void	dda(int X0, int Y0, int X1, int Y1, t_game *game)
{
    int dx = X1 - X0;
    int dy = Y1 - Y0;
  
    // calculate steps required for generating pixels
    int steps = _abs(dx) > _abs(dy) ? _abs(dx) : _abs(dy);
  
    // calculate increment in x & y for each steps
    float Xinc = dx / (float)steps;
    float Yinc = dy / (float)steps;
  
    // Put pixel for each step
    float X = X0;
    float Y = Y0;
    for (int i = 0; i <= steps; i++) {
        mlx_put_pixel(game->mlx.window, round(X), round(Y),
                 get_rgba(0,0,0,255)); // put pixel at (X,Y)
        X += Xinc; // increment in x at each step
        Y += Yinc; // increment in y at each step
                    // generation step by step
    }
}
