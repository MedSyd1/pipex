/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoufid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 21:58:31 by mmoufid           #+#    #+#             */
/*   Updated: 2022/12/21 22:02:17 by mmoufid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	**freememory(char **str, int l)
{
	while (l)
		free(str[l --]);
	free(str);
	return (NULL);
}

static int	ft_countstrings(const char*s, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**t;
	int		i;
	int		j;
	int		l;

	if (!s)
		return (NULL);
	t = (char **)malloc(sizeof(char *) *(ft_countstrings(s, c) + 1));
	if (!t)
		return (NULL);
	i = 0;
	j = 0;
	l = -1;
	while (++l < ft_countstrings(s, c))
	{
		while (s[i] == c)
			i++;
		j = i;
		while (s[i] != c && s[i])
			i++;
		t[l] = ft_substr(s, j, i - j);
		if (!t[l])
			return (freememory(t, l));
	}
	return (t[l] = NULL, t);
}
