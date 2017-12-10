/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floatarraynew.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 15:07:03 by dgerard           #+#    #+#             */
/*   Updated: 2017/07/07 08:20:10 by dgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float			*ft_floatarraynew(size_t x)
{
	size_t	i;
	float	*fresh;

	i = -1;
	fresh = ft_memalloc(sizeof(float) * x);
	while (i++ < x)
		fresh[i] = 0;
	return (fresh);
}
