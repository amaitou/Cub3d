/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_reader.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 19:40:27 by amait-ou          #+#    #+#             */
/*   Updated: 2023/09/04 14:39:23 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	skip_new_lines(char *s, int *i)
{
	while (*(s + (*i)) && *(s + (*i)) != '\n')
		(*i)++;
	return (*i);
}

static int	skip_chars(char *s, int *i)
{
	while (*(s + (*i)) && *(s + (*i)) == '\n')
		(*i)++;
	return (*i);
}

static int	consecutive_new_lines(char *s, int i)
{
	while (s[i])
	{
		if (s[i] == '\n' && s[i + 1] && s[i + 1] == '\n')
		{
			free(s);
			return (1);
		}
		++i;
	}
	return (0);
}

int	check_consecutive_new_lines(char *s)
{
	char	*str;
	int		counter;
	int		i;

	str = ft_strtrim(s, "\n");
	i = 0;
	counter = 0;
	while (s[i])
	{
		i = skip_new_lines(s, &i);
		if (s[i])
		{
			counter++;
			i = skip_chars(s, &i);
		}
		if (counter == 6)
			break ;
	}
	if (consecutive_new_lines(str, i))
		return (1);
	free(str);
	return (0);
}
