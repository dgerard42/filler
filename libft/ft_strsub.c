/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 12:26:23 by dgerard           #+#    #+#             */
/*   Updated: 2017/05/16 21:24:13 by dgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(const char *s, unsigned int start, size_t len)
{
	int		i;
	char	*fresh;

	i = 0;
	if (!*s)
		return (NULL);
	else if (!(fresh = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (s[i] && i < (int)len && (size_t)start < ft_strlen(s))
	{
		fresh[i] = s[i + start];
		i++;
	}
	fresh[i] = '\0';
	return (fresh);
}
