/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 03:43:49 by amait-ou          #+#    #+#             */
/*   Updated: 2023/10/05 18:12:21 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

static int	words(const char *s)
{
	int		i;
	char	*p;

	i = 0;
	p = (char *)s;
	while (*p)
	{
		while ((*p == ' ' || *p == '\t') && *p)
			++p;
		if (*p)
		{
			while (*p && *p != ' ' && *p != '\t')
				++p;
			++i;
		}
	}
	return (i);
}

static int	letters(const char *s, int position)
{
	int		i;
	char	*p;

	p = (char *)s;
	i = 0;
	while (*(p + position)
		&& *(p + position) != ' ' && *(p + position) != '\t')
	{
		++i;
		++position;
	}
	return (i);
}

static char	**allocation(char **p, char const *s, int i)
{
	int	k;
	int	j;

	j = 0;
	while (s[i])
	{
		k = 0;
		while (s[i] && (s[i] == ' ' || s[i] == '\t'))
			++i;
		if (s[i])
		{
			p[j] = (char *)malloc(sizeof(char) * (letters(s, i) + 1));
			while (s[i] && s[i] != ' ' && s[i] != '\t')
			{
				if (!p[j])
					return ((void *)0);
				p[j][k++] = s[i];
				++i;
			}
			p[j++][k] = '\0';
		}
	}
	p[j] = (void *)0;
	return (p);
}

char	**split2(char const *s)
{
	char	**p;
	int		i;

	i = 0;
	if (!s)
		return ((void *)0);
	p = (char **)malloc(sizeof(char *) * (words(s) + 1));
	if (!p)
		return ((void *)0);
	allocation(p, s, i);
	return (p);
}
