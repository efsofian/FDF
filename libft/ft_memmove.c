/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seliasbe <seliasbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 15:18:45 by seliasbe          #+#    #+#             */
/*   Updated: 2017/05/24 20:59:24 by seliasbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	if (s2 <= s1)
		while (n--)
			((unsigned char*)s1)[n] = ((unsigned char*)s2)[n];
	else
		ft_memcpy(s1, s2, n);
	return ((void*)s1);
}
