/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seliasbe <seliasbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 21:34:10 by seliasbe          #+#    #+#             */
/*   Updated: 2017/10/29 02:04:16 by seliasbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <errno.h>
# include <mlx.h>
# include "libft/includes/libft.h"
# define WINX 1000
# define WINY 800

typedef struct	s_point
{
	int x;
	int y;
	int z;
}				t_point;

typedef struct	s_elements
{
	int			nbline;
	int			nbcol;
	int			xstart;
	int			ystart;
	int			height;
	int			**finalmap;
	double		len;
	double		width;
	void		*mlx;
	void		*wind;
	t_point		**coo;
}				t_elements;

void			print_error(char *str);
void			import_map(char *map);
void			key_hook_2(int keycode, t_elements *elems);
void			firstinit(int **tab, int nbline, int nbcol);
void			printline(t_elements *elems, t_point point1, t_point point2);
void			removeline(t_elements *elems, t_point point1, t_point point2);
void			printmap(t_elements *elems);
void			remove_map(t_elements *elems);
void			print_options(t_elements *elems);
void			remove_options(t_elements *elems);
t_point			ipt(int x, int y, int z);
t_point			**coord(int line, int col, t_elements *elems);
int				key_hook(int keycode, t_elements *elems);
int				expose_hook(t_elements *elems);
int				whatcolor(int nb);
#endif
