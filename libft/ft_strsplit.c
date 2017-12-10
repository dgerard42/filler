/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 22:17:40 by dgerard           #+#    #+#             */
/*   Updated: 2017/05/16 18:17:25 by dgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_wordcount(const char *s, char c)
{
	int words;

	words = 0;
	while (*s)
	{
		while (*s && *s != c)
			s++;
		while (*s == c)
			s++;
		words++;
	}
	return (words);
}

static char			**ft_dyn2dstrnew(const char *s, char c)
{
	int		word_size;
	char	**res;
	char	**ret;

	if (!(res = (char **)malloc(sizeof(char *) * (ft_wordcount(s, c) + 1))))
		return (NULL);
	ret = res;
	while (*s)
	{
		word_size = 0;
		while (*s && *s != c)
		{
			s++;
			word_size++;
		}
		while (*s == c)
			s++;
		if (!(*res = (char *)malloc(sizeof(char) * (word_size + 1))))
			return (NULL);
		res++;
	}
	return (ret);
}

char				**ft_strsplit(const char *s, char c)
{
	int		j;
	int		k;
	char	*trimd;
	char	**res;

	j = 0;
	trimd = ft_customtrim(s, c);
	if (!trimd)
		return (NULL);
	res = ft_dyn2dstrnew(trimd, c);
	if (!res)
		return (NULL);
	while (*trimd)
	{
		k = 0;
		while (*trimd && *trimd != c)
			res[j][k++] = *trimd++;
		res[j][k] = '\0';
		while (c == *trimd)
			trimd++;
		j++;
	}
	res[j] = (NULL);
	return (res);
}
