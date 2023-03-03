/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoufid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 21:58:36 by mmoufid           #+#    #+#             */
/*   Updated: 2022/12/23 01:05:48 by mmoufid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	checkminus(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '-')
			count ++;
		i ++;
	}
	return (count);
}

char	*getcmd(char *arg)
{
	if (ft_strchr(arg, ' ') == 0)
		return (arg);
	else
		return (ft_substr(arg, 0, (int)ft_strchr(arg, ' ')));
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*ft_dst;
	unsigned char	*ft_src;
	size_t			i;

	ft_dst = (unsigned char *)dst;
	ft_src = (unsigned char *)src;
	if (ft_dst == ft_src)
		return (dst);
	i = -1;
	while (++i < n)
		*(ft_dst++) = *(ft_src++);
	return (dst);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*t;

	i = 0;
	t = (char *)malloc(sizeof(char ) * ft_strlen(s1) + 1);
	if (!t)
		return (NULL);
	while (*s1)
		t[i++] = *s1++;
	t[i] = '\0';
	return (t);
}
