/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 14:46:33 by dgerard           #+#    #+#             */
/*   Updated: 2017/05/16 18:13:14 by dgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strlcat(char *dst, const char *src, size_t size)
{
	int		i;
	int		j;
	size_t	dstlen;
	size_t	srclen;

	i = 0;
	j = 0;
	dstlen = (size_t)ft_strlen(dst);
	srclen = (size_t)ft_strlen(src);
	while (dst[i] != '\0')
		i++;
	while (*src != '\0' && i < ((int)size - 1))
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return ((size <= dstlen) ? (srclen + size) : (dstlen + srclen));
}
