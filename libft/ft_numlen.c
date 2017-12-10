/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 16:36:37 by dgerard           #+#    #+#             */
/*   Updated: 2017/07/28 16:36:56 by dgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int						ft_numlen(int value, int base)
{
	int len;

	len = (value == 0) ? 1 : 0;
	if (value < 0)
	{
		len = (base == 10) ? 2 : 1;
		value = value / base;
		value = -value;
	}
	while (value > 0)
	{
		value = value / base;
		len++;
	}
	return (len);
}
