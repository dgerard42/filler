/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 18:43:17 by dgerard           #+#    #+#             */
/*   Updated: 2017/03/24 18:53:16 by dgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *list, t_list *(*f)(t_list *elem))
{
	t_list	*fresh;
	t_list	*current;
	t_list	*tmp;

	tmp = 0;
	fresh = 0;
	tmp = f(list);
	current = ft_lstnew(tmp->content, tmp->content_size);
	list = list->next;
	while (list != NULL)
	{
		tmp = f(list);
		current->next = ft_lstnew(tmp->content, tmp->content_size);
		if (!fresh)
			fresh = current;
		current = current->next;
		list = list->next;
	}
	return (fresh);
}
