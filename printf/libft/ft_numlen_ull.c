/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen_ull.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 15:04:43 by dgerard           #+#    #+#             */
/*   Updated: 2017/08/04 15:04:45 by dgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int						ft_numlen_ull(uintmax_t value, unsigned int base)
{
	int		len;

	len = (value == 0) ? 1 : 0;
	while (value != 0)
	{
		value = value / base;
		len++;
	}
	return (len);
}
