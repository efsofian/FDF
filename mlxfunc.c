/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxfunc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seliasbe <seliasbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 16:30:10 by seliasbe          #+#    #+#             */
/*   Updated: 2017/10/29 02:07:19 by seliasbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point		**coord(int l, int c, t_elements *el)
{
	int		i;
	int		j;
	int		start;
	t_point	**coord;

	i = 0;
	start = el->xstart;
	coord = (t_point**)malloc(sizeof(t_point*) * (l));
	while (i < l)
	{
		j = 0;
		while (j < c)
		{
			if (j == 0)
				coord[i] = (t_point*)malloc(sizeof(t_point) * c);
			coord[i][j] = ipt(start + j * el->width, el->ystart
					+ i * el->height - el->len * el->finalmap[i][j],
					whatcolor(el->finalmap[i][j]));
			j++;
		}
		start -= el->width;
		i++;
	}
	return (coord);
}

void		printline(t_elements *el, t_point point1, t_point point2)
{
	int		err;
	int		err2;
	t_point	d;
	t_point	s;

	d = ipt(abs(point2.x - point1.x), abs(point2.y - point1.y), 0);
	s = ipt((point1.x < point2.x ? 1 : -1), (point1.y < point2.y ? 1 : -1), 0);
	err = (d.x > d.y ? d.x : -d.y) / 2;
	while (42)
	{
		mlx_pixel_put(el->mlx, el->wind, point1.x, point1.y, point1.z);
		if (point1.x == point2.x && point1.y == point2.y)
			break ;
		err2 = err;
		if (err2 > -d.x)
		{
			err -= d.y;
			point1.x += s.x;
		}
		if (err2 < d.y)
		{
			err += d.x;
			point1.y += s.y;
		}
	}
}

void		removeline(t_elements *el, t_point point1, t_point point2)
{
	int		err;
	int		err2;
	t_point	d;
	t_point	s;

	d = ipt(abs(point2.x - point1.x), abs(point2.y - point1.y), 0);
	s = ipt((point1.x < point2.x ? 1 : -1), (point1.y < point2.y ? 1 : -1), 0);
	err = (d.x > d.y ? d.x : -d.y) / 2;
	while (42)
	{
		mlx_pixel_put(el->mlx, el->wind, point1.x, point1.y, 0x000000);
		if (point1.x == point2.x && point1.y == point2.y)
			break ;
		err2 = err;
		if (err2 > -d.x)
		{
			err -= d.y;
			point1.x += s.x;
		}
		if (err2 < d.y)
		{
			err += d.x;
			point1.y += s.y;
		}
	}
}

void		printmap(t_elements *el)
{
	int		i;
	int		j;

	i = 0;
	while (i < el->nbline)
	{
		j = 0;
		while (j < el->nbcol)
		{
			if (j != el->nbcol - 1)
				printline(el, el->coo[i][j], el->coo[i][j + 1]);
			if (i != el->nbline - 1)
				printline(el, el->coo[i][j], el->coo[i + 1][j]);
			j++;
		}
		i++;
	}
}

void		firstinit(int **tab, int nbline, int nbcol)
{
	t_elements	el;

	el.mlx = mlx_init();
	el.wind = mlx_new_window(el.mlx, WINX, WINY, "42 FDF");
	el.nbline = nbline;
	el.nbcol = nbcol;
	el.finalmap = tab;
	el.width = 4;
	el.height = 7;
	el.xstart = (WINX - (el.nbcol / 2 * el.width)) / 2;
	el.ystart = (WINY - (el.nbline * el.height)) / 2;
	el.len = 1;
	el.coo = coord(el.nbline, el.nbcol, &el);
	print_options(&el);
	mlx_expose_hook(el.wind, expose_hook, &el);
	mlx_key_hook(el.wind, key_hook, &el);
	mlx_loop(el.mlx);
}
