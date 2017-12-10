/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/23 17:17:59 by dgerard           #+#    #+#             */
/*   Updated: 2017/08/14 20:43:16 by dgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uintmax_t			typecast_unum(t_flags *flags, uintmax_t nbr)
{
	if (flags->spec == 7)
		return (nbr);
	if (flags->length == 4 || (flags->caps == true && flags->spec != 6))
		nbr = (unsigned long)nbr;
	else if (flags->length == 0)
		nbr = (unsigned int)nbr;
	else if (flags->length == 1)
		nbr = (unsigned char)nbr;
	else if (flags->length == 2)
		nbr = (unsigned short)nbr;
	else if (flags->length == 6)
		nbr = (size_t)nbr;
	return (nbr);
}

intmax_t			typecast_num(t_flags *flags, intmax_t nbr)
{
	if (flags->length == 4 || (flags->caps == true && flags->spec == 2))
		nbr = (long int)nbr;
	else if (flags->length == 0)
		nbr = (int)nbr;
	else if (flags->length == 1)
		nbr = (signed char)nbr;
	else if (flags->length == 2)
		nbr = (short int)nbr;
	else if (flags->length == 6)
		nbr = (size_t)nbr;
	return (nbr);
}

void				parse_args(t_flags *flags, va_list *arg)
{
	if (flags->spec == 1 || flags->spec == 8)
		print_char(flags, arg);
	else if (flags->spec == 2)
		print_signed(flags, arg, 10);
	else if (flags->spec == 3)
		print_unsigned(flags, arg, 8);
	else if (flags->spec == 4)
		print_string(flags, arg);
	else if (flags->spec == 6 || flags->spec == 7)
		print_unsigned(flags, arg, 16);
	else if (flags->spec == 5)
		print_unsigned(flags, arg, 10);
}
