/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoini.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 14:20:30 by dgerard           #+#    #+#             */
/*   Updated: 2017/07/07 20:52:34 by dgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoini(const char *s1, const char *s2, size_t i)
{
	char	*fresh;

	fresh = ft_strjoin(s1, s2);
	if (i == 1 || i == 3)
		free((void *)s1);
	if (i == 2 || i == 3)
		free((void *)s2);
	return (fresh);
}
