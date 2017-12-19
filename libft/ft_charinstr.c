/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charinstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seliasbe <seliasbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 21:28:37 by seliasbe          #+#    #+#             */
/*   Updated: 2017/05/24 20:57:52 by seliasbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_charinstr(const char *str, char c)
{
	int i;

	i = 0;
	if (!*str)
		return (-1);
	while (*str)
	{
		if (*str == c)
			i++;
		str++;
	}
	return (i);
}
