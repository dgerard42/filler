/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_customtrim.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 18:57:01 by dgerard           #+#    #+#             */
/*   Updated: 2017/05/17 14:32:00 by dgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_ifcbefore(const char *s, char c)
{
	int i;

	i = 0;
	if (s[0] == c)
		while (s[i] == c)
			i++;
	return (i);
}

static int		ft_ifcafter(const char *s, char c)
{
	int i;
	int j;

	i = (ft_strlen(s) - 1);
	j = i;
	if (s[j] == c)
		while (i > 0 && (s[i] == c))
			i--;
	return (ft_strlen(s) - i);
}

char			*ft_customtrim(const char *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	*fresh;

	j = 0;
	i = ft_ifcbefore(s, c);
	k = (ft_strlen(s) - ft_ifcafter(s, c) + 1);
	if ((k - i) < 0)
		k = (i + 1);
	if (!(fresh = (char *)malloc(sizeof(char) * ((k - i) + 1))))
		return (NULL);
	while (i < k)
	{
		fresh[j] = s[i];
		j++;
		i++;
	}
	fresh[j] = '\0';
	return (fresh);
}
