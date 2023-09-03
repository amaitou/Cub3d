/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 15:28:15 by amait-ou          #+#    #+#             */
/*   Updated: 2023/09/03 16:08:49 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_for_weird_chars(char *s)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (s[i])
	{
		if (s[i] == ',')
			c++;
		if (!((s[i] >= '0' && s[i] <= '9') || (s[i] == ',' || s[i])))
			return (1);
		++i;
	}
	if (!(c == 2))
		return (2);
	return (0);
}

int	check_rgb_range(char *s)
{
	int		return_value;
	char	**p;
	int		i;

	return_value = check_for_weird_chars(s);
	if (return_value)
		return (return_value);
	p = ft_split(s, ',');
	if (ft_array_len(p) != 3)
	{
		free_array(p);
		return (3);
	}
	i = -1;
	while (p[++i])
	{
		if (!(ft_atoi(p[i]) >= 0 && ft_atoi(p[i]) <= 255))
		{
			free_array(p);
			return (4);
		}
	}
	free_array(p);
	return (0);
}

int	print_error(char *s)
{
	int	return_value;

	return_value = check_rgb_range(s);
	if (return_value == 1)
		ft_putendl_fd("Error: RGB Contains Weird Chars", 2);
	else if (return_value == 2)
		ft_putendl_fd("Error: Format Of RGB Is Invalid", 2);
	else if (return_value == 3)
		ft_putendl_fd("Error: There is a Missing Part of RGB", 2);
	else if (return_value == 4)
		ft_putendl_fd("Error: RGB Is Out Of Range", 2);
	return (return_value);
}

int	check_rgb(t_game *game)
{
	if (print_error(game->elements.floor_c.rgb))
		return (1);
	if (print_error(game->elements.ceiling_c.rgb))
		return (2);
	return (0);
}
