/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seliasbe <seliasbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 12:46:41 by seliasbe          #+#    #+#             */
/*   Updated: 2017/05/24 20:59:06 by seliasbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char		*tempdest;
	const char	*tempsrc;

	tempdest = dest;
	tempsrc = src;
	while (n--)
	{
		if (*tempsrc == c)
		{
			*tempdest++ = *tempsrc++;
			return (tempdest);
		}
		*tempdest++ = *tempsrc++;
	}
	return (NULL);
}
