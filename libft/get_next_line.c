/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seliasbe <seliasbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 16:46:14 by seliasbe          #+#    #+#             */
/*   Updated: 2017/10/29 02:05:51 by seliasbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

static int	get_line(const int fd, char *buffer, char *mybuff[fd])
{
	int		valueread;
	char	*temp;

	while ((ft_strchr(buffer, '\n')) == NULL
			&& (valueread = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[valueread] = '\0';
		temp = mybuff[fd];
		mybuff[fd] = ft_strjoin(temp, buffer);
		ft_strdel(&temp);
	}
	ft_strdel(&buffer);
	if (valueread == -1)
		return (-1);
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static char		*mybuff[MAX_VALUE_FD];
	char			*buffer;
	int				readval;
	char			*fullstrleft;
	char			*temp;

	buffer = ft_strnew(BUFF_SIZE);
	if (fd < 0 || BUFF_SIZE <= 0 || line == NULL || buffer == NULL)
		return (-1);
	if (mybuff[fd] == NULL)
		mybuff[fd] = ft_strnew(1);
	if ((readval = get_line(fd, buffer, mybuff)) == -1)
		return (-1);
	if ((fullstrleft = ft_strchr(mybuff[fd], '\n')) != NULL)
	{
		*line = ft_strsub(mybuff[fd], 0, fullstrleft - mybuff[fd]);
		temp = mybuff[fd];
		mybuff[fd] = ft_strdup(fullstrleft + 1);
		ft_strdel(&temp);
		return (1);
	}
	*line = ft_strdup(mybuff[fd]);
	mybuff[fd] = NULL;
	return (ft_strlen(*line) > 0 ? 1 : 0);
}
