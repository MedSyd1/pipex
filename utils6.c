/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoufid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 13:56:25 by mmoufid           #+#    #+#             */
/*   Updated: 2022/12/25 15:00:36 by mmoufid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	checkcmd(char *cmd)
{
	if (*cmd == '/' || *cmd == '.' )
		return (-1);
	else
		return (0);
}

int	check(char *cmd)
{
	if (cmd[0] == '/' || cmd[0] == '.')
		return (-1);
	return (0);
}

char	*ft_memchr(char *s, int c, size_t n)
{
	char	*t;

	t = s;
	while (n --)
	{
		if (t[n] == (unsigned char)c)
		{
			return (t + n + 1);
		}
	}
	return (NULL);
}
