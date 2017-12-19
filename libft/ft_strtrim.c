/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seliasbe <seliasbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 16:10:29 by seliasbe          #+#    #+#             */
/*   Updated: 2017/05/24 21:02:00 by seliasbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdlib.h>

static int		ft_lenfinal(char const *s)
{
	int		i;
	int		n;

	i = 0;
	n = 0;
	while ((s[i] != '\0') &&
			((s[i] == ' ') || (s[i] == '\n') || (s[i] == '\t')))
		i++;
	n = ft_strlen((char *)s);
	if ((s[n - 1] == ' ') || (s[n - 1] == '\n') || (s[n - 1] == '\t'))
		n--;
	while ((n > 0) && ((s[n] == ' ') || (s[n] == '\n') || (s[n] == '\t')))
		n--;
	if (n > 0)
		return (n - i);
	return (0);
}

char			*ft_strtrim(const char *s)
{
	int		i;

	i = 0;
	if (s != NULL)
	{
		while ((s[i] != '\0') && ((s[i] == ' ') || (s[i] == '\n') ||
					(s[i] == '\t')))
			i++;
		return (ft_strsub(s, i, ft_lenfinal(s) + 1));
	}
	return (NULL);
}
