/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seliasbe <seliasbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 15:58:24 by seliasbe          #+#    #+#             */
/*   Updated: 2017/05/24 21:01:39 by seliasbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*s;
	size_t	i;

	i = 0;
	if ((s = ft_memalloc(++size)) == NULL)
		return (NULL);
	while (i < size)
		s[i++] = '\0';
	return (s);
}
