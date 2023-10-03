/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 06:14:23 by amait-ou          #+#    #+#             */
/*   Updated: 2023/10/03 02:10:52 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	check_for_commas(char *s)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (s[i])
	{
		if (s[i] == ',')
			++c;
		++i;
	}
	if (c < 2 || c > 2)
		return (1);
	return (0);
}

static int	check_weird_chars(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		while (s[i] && (s[i] == ' ' || s[i] == '\t'))
			++i;
		if (s[i] == '-' || s[i] == '+')
			++i;
		if (s[i])
		{
			while (s[i])
			{
				if (!(s[i] >= '0' && s[i] <= '9'))
					return (1);
				++i;
			}
		}
	}
	return (0);
}

static int	check_range(char *s)
{
	char	**p;
	int		n;
	int		i;

	p = ft_split(s, ',');
	i = 0;
	while (p[i])
	{
		if (check_weird_chars(p[i]))
			return (2);
		n = ft_atoi(p[i]);
		if (n < 0 || n > 255)
		{
			free_array(p);
			return (3);
		}
		++i;
	}
	free_array(p);
	return (0);
}

static int	check_color(char *s, t_enums color)
{
	if (s == NULL || color == _NONE)
		return (1);
	return (0);
}

int	__rgb(t_game *game)
{
	t_color_c	ceiling;
	t_color_f	floor;
	int			temp1;
	int			temp2;

	ceiling = game->elements.ceiling_c;
	floor = game->elements.floor_c;
	if (check_color(ceiling.surface, ceiling.type)
		|| check_color(floor.surface, floor.type))
		return (5);
	if (check_for_commas(ceiling.rgb) || check_for_commas(floor.rgb))
		return (1);
	temp1 = check_range(ceiling.rgb);
	temp2 = check_range(floor.rgb);
	if (temp1)
		return (temp1);
	if (temp2)
		return (temp2);
	return (0);
}
