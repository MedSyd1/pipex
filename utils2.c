/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoufid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 21:58:33 by mmoufid           #+#    #+#             */
/*   Updated: 2022/12/23 14:56:49 by mmoufid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*substring;

	i = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
	{
		substring = malloc(sizeof(char ));
		if (!substring)
			return (NULL);
		*substring = '\0';
		return (substring);
	}
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	substring = (char *)malloc(sizeof(char) * len + 1);
	if (!substring)
		return (NULL);
	while (i < len)
		substring[i++] = s[start++];
	substring[len] = '\0';
	return (substring);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	str2 = (unsigned char *)s2;
	str1 = (unsigned char *)s1;
	i = 0;
	while (i < n)
	{
		if (str1[i] == str2[i])
			i++;
		else
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
	}
	return (0);
}

int	ft_strchr(const char *hay, int c)
{
	int	i;

	i = 0;
	while (i <= (int)ft_strlen(hay))
	{
		if (hay[i] == (char)c)
			return (i);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*t;

	if (!s1 || !s2)
		return (NULL);
	if (!*s1 && !*s2)
	{
		t = malloc(1);
		*t = '\0';
		return (t);
	}
	t = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!t)
		return (NULL);
	ft_memcpy(t, s1, ft_strlen(s1));
	ft_memcpy(t + ft_strlen(s1), s2, ft_strlen(s2));
	t[ft_strlen(s2) + ft_strlen(s1)] = '\0';
	return (t);
}
