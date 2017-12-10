/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 12:26:23 by dgerard           #+#    #+#             */
/*   Updated: 2017/05/17 14:36:45 by dgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(const char *s1, const char *s2)
{
	size_t	i;
	char	*fresh;
	size_t	len;

	i = 0;
	len = (ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!(fresh = (char*)malloc(len)))
		return (NULL);
	while (i < (len - 1))
	{
		while (*s1)
		{
			fresh[i] = *s1++;
			i++;
		}
		while (*s2)
		{
			fresh[i] = *s2++;
			i++;
		}
	}
	fresh[i] = '\0';
	return (fresh);
}
