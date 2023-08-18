/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 22:24:19 by amait-ou          #+#    #+#             */
/*   Updated: 2023/08/18 15:46:09 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./superlib.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*p;

	p = malloc((string_len((char *)s1) + string_len((char *)s2)) + 1);
	if (!p)
		return ((void *)0);
	i = 0;
	j = 0;
	while (s1 && s1[i])
	{
		p[i] = s1[i];
		++i;
	}
	while (s2[j])
	{
		p[i] = s2[j];
		++j;
		++i;
	}
	p[i] = '\0';
	free((char *)s1);
	free((char *)s2);
	return (p);
}
