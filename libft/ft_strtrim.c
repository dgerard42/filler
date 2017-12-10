/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 18:57:01 by dgerard           #+#    #+#             */
/*   Updated: 2017/05/17 14:34:53 by dgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_ifbefore(const char *s)
{
	int i;

	i = 0;
	if (s[0] == ' ' || s[0] == '\t' || s[0] == '\n')
		while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
			i++;
	return (i);
}

static int		ft_ifafter(const char *s)
{
	int i;
	int j;

	i = (ft_strlen(s) - 1);
	j = i;
	if (s[j] == ' ' || s[j] == '\t' || s[j] == '\n')
		while (i > 0 && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'))
			i--;
	return (ft_strlen(s) - i);
}

char			*ft_strtrim(const char *s)
{
	int		i;
	int		j;
	int		k;
	char	*fresh;

	j = 0;
	i = ft_ifbefore(s);
	k = (ft_strlen(s) - ft_ifafter(s) + 1);
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
