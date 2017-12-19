/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seliasbe <seliasbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 09:28:03 by seliasbe          #+#    #+#             */
/*   Updated: 2017/05/24 21:00:50 by seliasbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		n;
	size_t		len;

	len = 0;
	while (len < size && *dst && *(dst++))
		len++;
	n = size - len;
	if (!n)
		return (len + ft_strlen(src));
	while (*src)
	{
		if (n != 1)
		{
			*(dst++) = *src;
			n--;
		}
		src++;
		len++;
	}
	*dst = '\0';
	return (len);
}
