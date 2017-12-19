/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seliasbe <seliasbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 15:44:23 by seliasbe          #+#    #+#             */
/*   Updated: 2017/05/24 21:00:58 by seliasbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdlib.h>

char	*ft_strmap(const char *s, char (*f)(char))
{
	char	*new;
	int		i;

	i = 0;
	if (!s || !f)
		return (NULL);
	if (!(new = ft_strdup(s)))
		return (NULL);
	while (s[i])
	{
		new[i] = (*f)(s[i]);
		i++;
	}
	new[i] = '\0';
	return (new);
}
