/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seliasbe <seliasbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 16:02:19 by seliasbe          #+#    #+#             */
/*   Updated: 2017/10/29 02:08:16 by seliasbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		count_col(char *map)
{
	int i;
	int count;
	int help;

	i = 0;
	count = 0;
	help = 0;
	while (map[i] != '\0' && map[i] != '\n')
	{
		if (map[i] != ' ' && help == 0)
		{
			count++;
			help = 1;
		}
		if (help == 1 && map[i] == ' ')
			help = 0;
		i++;
	}
	return (count);
}

int		count_line(char *map)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (map[i] != '\0')
	{
		if (map[i] == '\n')
			count++;
		i++;
	}
	return (count);
}

int		**filltab(char **split, int nbcol, int nbline)
{
	int **tab;
	int i;
	int j;
	int k;

	tab = (int**)malloc(sizeof(int*) * (nbline));
	i = 0;
	j = 0;
	k = 0;
	while (split[k] != '\0')
	{
		if (j == 0)
			tab[i] = (int *)malloc(sizeof(int) * (nbcol));
		tab[i][j] = ft_atoi(split[k]);
		j++;
		k++;
		if (j >= nbcol)
		{
			j = 0;
			i++;
		}
	}
	return (tab);
}

char	*withoutslashn(char *map, int c, int i)
{
	int help;
	int count;

	help = 0;
	count = 0;
	while (map[i])
	{
		if (map[i] == '\n')
		{
			map[i] = ' ';
			if (count % c != 0)
				print_error("map error");
			count = 0;
			help = 0;
		}
		if (map[i] != ' ' && help == 0)
		{
			count++;
			help = 1;
		}
		if (help == 1 && map[i] == ' ')
			help = 0;
		i++;
	}
	return (map);
}

void	import_map(char *map)
{
	int		nbline;
	int		nbcol;
	char	**split;
	int		**tab;
	int		i;

	nbline = count_line(map);
	nbcol = count_col(map);
	map = withoutslashn(map, nbcol, 0);
	split = ft_strsplit(map, ' ');
	tab = filltab(split, nbcol, nbline);
	i = 0;
	while (split[i])
		i++;
	if (ft_strlen(map) == 0)
		print_error("empty map");
	if (nbline * nbcol != i)
		print_error("map error");
	firstinit(tab, nbline, nbcol);
}
