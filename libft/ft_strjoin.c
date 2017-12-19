/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seliasbe <seliasbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 15:47:12 by seliasbe          #+#    #+#             */
/*   Updated: 2017/05/24 21:00:47 by seliasbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdlib.h>

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*new;
	size_t	i;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	if (!(new = (char *)malloc(sizeof(char) *
					(ft_strlen(s1) + ft_strlen(s2)) + 1)))
		return (NULL);
	while (*s1)
		new[i++] = *(s1++);
	while (*s2)
		new[i++] = *(s2++);
	new[i] = '\0';
	return (new);
}
