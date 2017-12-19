/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printarray.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seliasbe <seliasbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 19:21:39 by seliasbe          #+#    #+#             */
/*   Updated: 2017/05/24 20:59:31 by seliasbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_printarray(char **array)
{
	int i;

	i = 0;
	while (array[i])
	{
		ft_putstr(array[i]);
		ft_putchar('\n');
		i++;
	}
}
