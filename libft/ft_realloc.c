/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 13:15:57 by dgerard           #+#    #+#             */
/*   Updated: 2017/05/16 18:14:19 by dgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_realloc(void *ptr, size_t size)
{
	void *fresh;

	if (ptr == NULL)
	{
		if (!(fresh = (void *)malloc((size))))
			return (NULL);
		ft_memdel(&ptr);
	}
	if (size == 0 && ptr)
	{
		if (!(fresh = (void *)malloc(1)))
			return (NULL);
	}
	else
	{
		if (!(fresh = (void *)malloc((size))))
			return (NULL);
		fresh = ft_memcpy(fresh, ptr, size);
		ft_memdel(&ptr);
	}
	return (fresh);
}
