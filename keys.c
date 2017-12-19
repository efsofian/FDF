/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seliasbe <seliasbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 17:27:13 by seliasbe          #+#    #+#             */
/*   Updated: 2017/10/25 16:45:49 by seliasbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	ipt(int x, int y, int z)
{
	t_point		point;

	point.x = x;
	point.y = y;
	point.z = z;
	return (point);
}

int		whatcolor(int nb)
{
	if (nb <= 0)
		return (0xDB0B32);
	if (nb <= 5)
		return (0xC4D7ED);
	if (nb <= 10)
		return (0x375D81);
	else if (nb <= 20)
		return (0x556627);
	else if (nb <= 30)
		return (0x8FCF3C);
	else if (nb <= 40)
		return (0xFF5B2B);
	else
		return (0xFFFFFF);
}

int		key_hook(int keycode, t_elements *el)
{
	remove_map(el);
	key_hook_2(keycode, el);
	if (keycode == 53)
		exit(0);
	else if (keycode == 69)
	{
		el->width++;
		el->height++;
	}
	else if (keycode == 78)
	{
		el->width--;
		el->height--;
	}
	else if (keycode == 2)
		el->len -= el->len * 0.5;
	if (keycode == 78 || keycode == 69 || keycode == 36)
	{
		el->xstart = (WINX - (el->nbcol / 2 * el->width)) / 2;
		el->ystart = (WINY - (el->nbline * el->height)) / 2;
	}
	el->coo = coord(el->nbline, el->nbcol, el);
	printmap(el);
	print_options(el);
	return (0);
}

void	key_hook_2(int keycode, t_elements *el)
{
	if (keycode == 124)
		el->xstart += 50;
	else if (keycode == 123)
		el->xstart -= 50;
	else if (keycode == 125)
		el->ystart += 25;
	else if (keycode == 126)
		el->ystart -= 25;
	else if (keycode == 34)
		el->len *= 1.5;
}

int		expose_hook(t_elements *el)
{
	printmap(el);
	return (0);
}
