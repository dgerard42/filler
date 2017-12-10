/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2dfreearray.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 20:20:43 by esterna           #+#    #+#             */
/*   Updated: 2017/07/07 21:02:45 by dgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_2dfreearray(void **array, int n)
{
	int i;
	int **tmp;

	i = 0;
	tmp = (int **)array;
	while (i < n)
	{
		ft_memdel((void**)&tmp[i]);
		i++;
	}
	ft_memdel(array);
}
