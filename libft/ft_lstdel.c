/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seliasbe <seliasbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 14:52:19 by seliasbe          #+#    #+#             */
/*   Updated: 2017/05/24 20:58:46 by seliasbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*elem;
	t_list	*tmp;

	elem = *alst;
	if (alst && *alst && (*del))
	{
		while (elem)
		{
			tmp = elem;
			elem = elem->next;
			(*del)(tmp->content, tmp->content_size);
			free(tmp);
		}
		*alst = NULL;
	}
}
