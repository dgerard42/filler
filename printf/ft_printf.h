/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 11:32:52 by dgerard           #+#    #+#             */
/*   Updated: 2017/08/23 16:50:53 by dgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdbool.h>

typedef	struct		s_flags
{
	unsigned char	flag;
	int				width;
	int				precision;
	int				length;
	int				spec;
	char			invalid_spec;
	bool			caps;
	int				written_chars;
}					t_flags;

int					ft_printf(const char *format, ...);
void				parse_args(t_flags *flags, va_list *arg);
void				ft_putchar_mem(t_flags *flags, char c);
void				ft_putnbr_mem(t_flags *flags, intmax_t nbr, int base);
void				ft_putunbr_mem(t_flags *flags, uintmax_t nbr, int base);
void				print_char(t_flags *flags, va_list *arg);
void				print_string(t_flags *flags, va_list *arg);
void				print_sign(t_flags *flags, intmax_t nbr);
void				print_prefix(t_flags *flags, uintmax_t nbr);
void				print_signed(t_flags *flags, va_list *arg, int base);
void				print_unsigned(t_flags *flags, va_list *arg, int base);
intmax_t			typecast_num(t_flags *flags, intmax_t nbr);
uintmax_t			typecast_unum(t_flags *flags, uintmax_t nbr);
const char			*check_flags(const char *format, t_flags *flags);
const char			*check_width_precision(const char *format, t_flags *flags);
const char			*check_length(const char *format, t_flags *flags);
const char			*check_specifier(const char *format, t_flags *flags);

#endif
