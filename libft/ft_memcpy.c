/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seliasbe <seliasbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 12:19:33 by seliasbe          #+#    #+#             */
/*   Updated: 2017/05/24 20:59:18 by seliasbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*tempdest;
	const unsigned char	*tempsrc;
	unsigned int		i;

	i = 0;
	tempdest = dest;
	tempsrc = src;
	while (i < n)
	{
		tempdest[i] = tempsrc[i];
		i++;
	}
	return (dest);
}
