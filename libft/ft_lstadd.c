/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seliasbe <seliasbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 14:44:31 by seliasbe          #+#    #+#             */
/*   Updated: 2017/05/24 20:58:44 by seliasbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_lstadd(t_list **alst, t_list *new)
{
	if (*alst == NULL)
		*alst = new;
	else if (new)
	{
		new->next = *alst;
		*alst = new;
	}
}
