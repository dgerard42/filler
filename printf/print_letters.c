/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_letters.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 21:02:11 by dgerard           #+#    #+#             */
/*   Updated: 2017/08/14 20:43:36 by dgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			print_char(t_flags *flags, va_list *arg)
{
	char	c;
	char	buffer;

	buffer = (flags->spec == 8 && flags->flag & 0b10000) ? '0' : ' ';
	if (flags->spec != 8)
		c = va_arg(*(arg), int);
	else
		c = flags->invalid_spec;
	if (flags->flag & 0b1)
		ft_putchar_mem(flags, c);
	while (flags->width-- > 1)
		ft_putchar_mem(flags, buffer);
	if (!(flags->flag & 0b1))
		ft_putchar_mem(flags, c);
}

void			print_string(t_flags *flags, va_list *arg)
{
	int		i;
	char	*string;
	int		spaces;
	int		length;

	i = 0;
	string = va_arg(*(arg), char *);
	if (!string)
		string = "(null)";
	length = (int)ft_strlen(string);
	spaces = flags->width - length;
	if (flags->precision < length && flags->precision != -1)
		spaces = spaces - (flags->precision - length);
	while (!(flags->flag & 0b1) && spaces-- > 0)
		ft_putchar_mem(flags, ' ');
	while (string[i] != '\0')
	{
		if (flags->precision != -1)
			if ((i + 1) > flags->precision)
				break ;
		ft_putchar_mem(flags, string[i++]);
	}
	while (flags->flag & 0b1 && spaces-- > 0)
		ft_putchar_mem(flags, ' ');
}
