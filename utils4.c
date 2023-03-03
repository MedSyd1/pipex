/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoufid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 22:11:56 by mmoufid           #+#    #+#             */
/*   Updated: 2022/12/25 15:44:26 by mmoufid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**getpaths(char **env)
{
	int		i;
	char	*str;

	i = 0;
	while (env[i])
	{
		str = ft_substr(env[i], 0, 5);
		if (ft_memcmp(str, "PATH=", 5) == 0)
		{
			if (str != NULL)
				free(str);
			return (ft_split(env[i] +5, ':'));
		}
		if (str != NULL)
			free(str);
		i++;
	}
	return (NULL);
}

void	child2requisite(int fds[2], int fd)
{
	if (dup2(fd, 1) == -1)
		return (perror("error"));
	if (dup2(fds[0], 0) == -1)
		return (perror("error"));
	close(fds[1]);
}

void	child2(char **env, char *command, char **arg2)
{
	char	**paths;

	paths = getpaths(env);
	execute(paths, env, command, arg2);
}

void	child1requisite(int fds[2], int fd)
{
	if (dup2(fd, 0) == -1)
	{
		perror("error");
		exit(-1);
	}
	if (dup2(fds[1], 1) == -1)
	{
		perror("error");
		exit(-1);
	}
	close(fds[0]);
}

void	child1(char **env, char *command, char **arg1)
{	
	char	**paths;

	paths = getpaths(env);
	execute(paths, env, command, arg1);
}
