/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2dintarray.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 14:22:54 by dgerard           #+#    #+#             */
/*   Updated: 2017/05/16 18:36:09 by dgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			**ft_2dintarray(size_t y, size_t x)
{
	size_t	subarray;
	int		**fresh;

	subarray = 0;
	fresh = ft_memalloc(sizeof(int *) * (y + 1));
	while (subarray <= y)
	{
		fresh[subarray] = ft_intarraynew(x);
		subarray++;
	}
	fresh[y + 1] = NULL;
	return (fresh);
}
