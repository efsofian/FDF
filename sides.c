/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sides.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seliasbe <seliasbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 15:26:36 by seliasbe          #+#    #+#             */
/*   Updated: 2017/10/29 02:17:37 by seliasbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_error(char *str)
{
	perror(str);
	exit(0);
}

void	remove_map(t_elements *el)
{
	int i;
	int j;

	i = 0;
	while (i < el->nbline)
	{
		j = 0;
		while (j < el->nbcol)
		{
			if (j != el->nbcol - 1)
				removeline(el, el->coo[i][j], el->coo[i][j + 1]);
			if (i != el->nbline - 1)
				removeline(el, el->coo[i][j], el->coo[i + 1][j]);
			j++;
		}
		i++;
	}
}

void	print_options(t_elements *el)
{
	remove_options(el);
	mlx_string_put(el->mlx, el->wind, 20, 20, 0x7FC6BC, "Arrow to moove");
	mlx_string_put(el->mlx, el->wind, 20, 40, 0x15453E, "+ / - to zoom");
	mlx_string_put(el->mlx, el->wind, 20, 60, 0xA71BB6, "i to increase z");
	mlx_string_put(el->mlx, el->wind, 20, 80, 0xB5E655, "d to decrease z");
	mlx_string_put(el->mlx, el->wind, 20, 100, 0x787746, "escape to exit");
}

void	remove_options(t_elements *el)
{
	mlx_string_put(el->mlx, el->wind, 20, 20, 0x000000, "Arrow to moove");
	mlx_string_put(el->mlx, el->wind, 20, 40, 0x000000, "+ / - to zoom");
	mlx_string_put(el->mlx, el->wind, 20, 60, 0x000000, "i to increase z");
	mlx_string_put(el->mlx, el->wind, 20, 80, 0x000000, "d to decrease z");
	mlx_string_put(el->mlx, el->wind, 20, 100, 0x000000, "escape to exit");
}
