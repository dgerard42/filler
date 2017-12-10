/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intarraynew.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 15:07:03 by dgerard           #+#    #+#             */
/*   Updated: 2017/05/17 14:39:27 by dgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			*ft_intarraynew(size_t x)
{
	size_t	i;
	int		*fresh;

	i = -1;
	fresh = ft_memalloc(sizeof(int) * x);
	while (i++ < x)
		fresh[i] = 0;
	return (fresh);
}
