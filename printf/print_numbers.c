/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 19:07:06 by dgerard           #+#    #+#             */
/*   Updated: 2017/08/14 20:44:05 by dgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				zeroes_signed(t_flags *flags, intmax_t nbr, int base)
{
	int zeroes;

	zeroes = 0;
	if (flags->precision >= ft_numlen_ll(nbr, base))
		zeroes = flags->precision - ft_numlen_ll(nbr, base);
	else if (flags->flag & 0b10000 && flags->width > 0 && !(flags->flag & 0b1))
	{
		zeroes = flags->width - ft_numlen_ll(nbr, base);
		if (nbr < 0 || flags->flag & 0b10 || flags->flag & 0b100)
			zeroes--;
	}
	return (zeroes);
}

void			print_signed(t_flags *flags, va_list *arg, int base)
{
	intmax_t	nbr;
	int			zeroes;
	int			spaces;

	spaces = 0;
	nbr = va_arg(*(arg), intmax_t);
	nbr = typecast_num(flags, nbr);
	zeroes = zeroes_signed(flags, nbr, base);
	spaces = flags->width - ft_numlen_ll(nbr, base) - zeroes;
	if (nbr == 0 && flags->precision == 0)
		spaces++;
	if (nbr < 0 || flags->flag & 0b10 || flags->flag & 0b100)
		spaces--;
	while (!(flags->flag & 0b1) && spaces-- > 0)
		ft_putchar_mem(flags, ' ');
	print_sign(flags, nbr);
	while (zeroes-- > 0)
		ft_putchar_mem(flags, '0');
	(flags->spec == 8) ? ft_putchar_mem(flags, nbr) :
		ft_putnbr_mem(flags, nbr, base);
	while (flags->flag & 0b1 && spaces-- > 0)
		ft_putchar_mem(flags, ' ');
}

int				zeroes_unsigned(t_flags *flags, uintmax_t nbr, int base)
{
	int zeroes;

	zeroes = 0;
	if (flags->precision >= ft_numlen_ull(nbr, base))
		zeroes = flags->precision - ft_numlen_ull(nbr, base);
	else if (flags->flag & 0b10000 && flags->width > 0 && !(flags->flag & 0b1))
	{
		zeroes = flags->width - ft_numlen_ull(nbr, base);
		if ((flags->flag & 0b1000 && flags->spec == 6) || flags->spec == 7)
			zeroes = zeroes - 2;
		else if (flags->flag & 0b1000 && flags->spec == 3)
			zeroes--;
	}
	return (zeroes);
}

void			print_unsigned(t_flags *flags, va_list *arg, int base)
{
	uintmax_t	nbr;
	int			zeroes;
	int			spaces;

	spaces = 0;
	nbr = va_arg(*(arg), uintmax_t);
	nbr = typecast_unum(flags, nbr);
	zeroes = zeroes_unsigned(flags, nbr, base);
	spaces = flags->width - ft_numlen_ull(nbr, base) - zeroes;
	if (flags->flag & 1000 && flags->spec == 3)
		zeroes--;
	if (nbr == 0 && flags->precision == 0)
		spaces++;
	if ((flags->flag & 0b1000 && flags->spec == 6) || flags->spec == 7)
		spaces = spaces - 2;
	else if (flags->flag & 0b1000 && flags->spec == 3)
		spaces--;
	while (!(flags->flag & 0b1) && spaces-- > 0)
		ft_putchar_mem(flags, ' ');
	print_prefix(flags, nbr);
	while (zeroes-- > 0)
		ft_putchar_mem(flags, '0');
	ft_putunbr_mem(flags, nbr, base);
	while (flags->flag & 0b1 && spaces-- > 0)
		ft_putchar_mem(flags, ' ');
}
