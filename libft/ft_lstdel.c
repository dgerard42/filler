/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 22:06:40 by dgerard           #+#    #+#             */
/*   Updated: 2017/03/24 01:15:35 by dgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*rmnode;

	rmnode = *alst;
	while (rmnode->next != NULL)
	{
		rmnode = *alst;
		ft_lstdelone(alst, del);
		*alst = rmnode->next;
	}
	*alst = (NULL);
}
