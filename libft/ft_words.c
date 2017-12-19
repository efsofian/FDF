/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_words.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seliasbe <seliasbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 20:42:02 by seliasbe          #+#    #+#             */
/*   Updated: 2017/05/24 21:02:17 by seliasbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int	ft_words(const char *s)
{
	int		i;
	int		words;

	i = 0;
	words = 0;
	while (s[i] && s[i] == ' ')
		i++;
	while (s[i])
	{
		while (s[i] && s[i] == ' ')
			i++;
		if (s[i])
		{
			while (s[i] && s[i] != ' ')
				i++;
			words++;
		}
	}
	return (words);
}
