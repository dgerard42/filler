/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 11:33:39 by dgerard           #+#    #+#             */
/*   Updated: 2017/08/14 20:41:26 by dgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const char			*print_format_string(const char *format, t_flags *flags)
{
	while (*format != '%' && *format)
		ft_putchar_mem(flags, *format++);
	if (*format && *format == '%')
		format++;
	return (format);
}

int					ft_printf(const char *format, ...)
{
	t_flags flags;
	va_list arg;

	va_start(arg, format);
	flags.written_chars = 0;
	while (*format)
	{
		format = print_format_string(format, &flags);
		format = check_flags(format, &flags);
		format = check_width_precision(format, &flags);
		format = check_length(format, &flags);
		format = check_specifier(format, &flags);
		if (flags.spec != 0)
			parse_args(&flags, &arg);
		if (*format)
			format++;
	}
	va_end(arg);
	return (flags.written_chars);
}
