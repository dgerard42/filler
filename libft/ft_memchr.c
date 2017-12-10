/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 15:58:09 by dgerard           #+#    #+#             */
/*   Updated: 2017/05/16 18:24:41 by dgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	ctmp;
	unsigned char	*stmp;

	i = 0;
	if (!n)
		return (NULL);
	ctmp = (unsigned char)c;
	stmp = (unsigned char *)s;
	while (i < (n - 1) && stmp[i] != ctmp)
		i++;
	return ((stmp[i] == ctmp) ? ((void *)(s + i)) : (NULL));
}
