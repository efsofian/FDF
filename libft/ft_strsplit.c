/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seliasbe <seliasbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 16:05:10 by seliasbe          #+#    #+#             */
/*   Updated: 2017/05/24 21:01:50 by seliasbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdlib.h>

static size_t	ft_letters(const char *s, char c)
{
	int		i;
	size_t	letters;

	i = 0;
	letters = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			while (s[i] && s[i] != c)
				i++;
			letters++;
		}
	}
	return (letters);
}

char			**ft_strsplit(const char *s, char c)
{
	char	**new;
	size_t	letterz;
	int		i;
	int		start;

	if (!s || !(new = (char **)malloc(sizeof(char *) * (ft_letters(s, c) + 1))))
		return (NULL);
	i = 0;
	letterz = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			start = i;
			while (s[i] && s[i] != c)
				i++;
			new[letterz++] = ft_strsub(s, start, i - start);
		}
	}
	new[letterz] = 0;
	return (new);
}
