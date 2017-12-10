/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 19:51:54 by dgerard           #+#    #+#             */
/*   Updated: 2017/05/16 18:18:34 by dgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_putnbr(int nbr)
{
	if (nbr == -2147483648)
	{
		ft_putnbr(nbr / 10);
		ft_putchar('8');
	}
	else if (nbr < 0)
	{
		ft_putchar('-');
		nbr = -nbr;
		if (nbr / 10 != 0)
			ft_putnbr(nbr / 10);
		ft_putchar((nbr % 10) + '0');
	}
	else
	{
		if (nbr > 9)
			ft_putnbr(nbr / 10);
		ft_putchar((nbr % 10) + '0');
	}
}
