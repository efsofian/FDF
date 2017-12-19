/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seliasbe <seliasbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 11:31:09 by seliasbe          #+#    #+#             */
/*   Updated: 2017/05/24 20:59:13 by seliasbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*temps1;
	unsigned char	*temps2;
	unsigned int	i;

	temps1 = (unsigned char *)s1;
	temps2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (*(temps1++) != *(temps2++))
			return (*(--temps1) - *(--temps2));
		i++;
	}
	return (0);
}
