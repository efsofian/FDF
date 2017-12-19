/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seliasbe <seliasbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 23:58:39 by seliasbe          #+#    #+#             */
/*   Updated: 2017/05/24 21:01:43 by seliasbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	int i;
	int j;
	int k;

	i = 0;
	if (!*s2)
		return ((char *)s1);
	while (s1[i] && n > 0)
	{
		j = 0;
		if (n < ft_strlen(s2))
			return (NULL);
		k = i;
		while (s1[k] == s2[j] && s2[j] && s1[k])
		{
			j++;
			k++;
		}
		if (!s2[j])
			return ((char *)(s1 + i));
		i++;
		n--;
	}
	return (NULL);
}
