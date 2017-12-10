/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 11:30:37 by dgerard           #+#    #+#             */
/*   Updated: 2017/07/07 20:51:47 by dgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char					base_assign(int num)
{
	int		i;
	char	*alnums;

	i = 0;
	alnums = "0123456789ABCDEF";
	while (num-- > 0)
		i++;
	return (alnums[i]);
}

char					*ft_itoa_base(int value, int base)
{
	int		size;
	int		isneg;
	char	*ret;

	isneg = 1;
	size = ft_numlen(value, base);
	ret = (char *)malloc((sizeof(char) * size + 1));
	ret[0] = (value < 0 && base == 10) ? '-' : '*';
	ret[size] = '\0';
	if (value == 0)
		ret[0] = '0';
	if (value < 0)
		isneg = -1;
	while (value != 0)
	{
		ret[size - 1] = base_assign((value % base) * isneg);
		value = value / base;
		size--;
	}
	return (ret);
}
