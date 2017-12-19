/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seliasbe <seliasbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 21:21:45 by seliasbe          #+#    #+#             */
/*   Updated: 2017/10/29 02:03:00 by seliasbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;
	char	*map;

	if (argc != 2)
		print_error("Entry Probem, usage: ./fdf map");
	else
	{
		if ((fd = open(argv[1], O_RDONLY)) != -1)
		{
			map = ft_strnew(1);
			while (get_next_line(fd, &line) > 0)
			{
				map = ft_strjoin(map, ft_strjoin(line, "\n"));
				free(line);
			}
			import_map(map);
		}
		else
			print_error("prob fd");
	}
	return (0);
}
