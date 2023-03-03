/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoufid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 15:02:00 by mmoufid           #+#    #+#             */
/*   Updated: 2022/12/25 14:25:18 by mmoufid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**getcommands(char *cmd1, char *cmd2)
{
	char	**commands;

	commands = (char **)malloc(2 * sizeof(char *));
	if (!commands)
		return (NULL);
	commands[0] = getcmd(cmd1);
	commands[1] = getcmd(cmd2);
	if (check(commands[0]) == -1)
		commands[0] = ft_memchr(commands[0], '/', ft_strlen(commands[0]));
	if (check(commands[1]) == -1)
		commands[1] = ft_memchr(commands[1], '/', ft_strlen(commands[1]));
	return (commands);
}

void	execute(char **paths, char **env, char *cmd, char **args)
{
	int		j;
	char	*path;

	j = 0;
	while (paths[j])
	{
		path = ft_strjoin(paths[j], ft_strjoin("/", cmd));
		if (access(path, F_OK | X_OK) == 0)
			if (execve(path, args, env) == -1)
				perror("error bro !!");
		if (path)
			free(path);
		j++;
	}
}
