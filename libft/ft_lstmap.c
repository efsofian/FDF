/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seliasbe <seliasbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 14:55:41 by seliasbe          #+#    #+#             */
/*   Updated: 2017/05/24 20:58:57 by seliasbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*new;
	t_list		*temp;
	t_list		*temp2;

	if (!lst || !f)
		return (NULL);
	temp2 = f(lst);
	if ((new = ft_lstnew(temp2->content, temp2->content_size)))
	{
		temp = new;
		lst = lst->next;
		while (lst)
		{
			temp2 = f(lst);
			if (!(temp->next = ft_lstnew(temp2->content, temp2->content_size)))
				return (NULL);
			temp = temp->next;
			lst = lst->next;
		}
	}
	return (new);
}
