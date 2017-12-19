/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seliasbe <seliasbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 11:47:09 by seliasbe          #+#    #+#             */
/*   Updated: 2017/05/24 20:59:10 by seliasbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char		*temps;
	unsigned int			i;

	i = 0;
	temps = (unsigned char *)s;
	while (i < n)
	{
		if (temps[i] == (unsigned char)c)
			return ((void *)&temps[i]);
		else
			i++;
	}
	return (NULL);
}
