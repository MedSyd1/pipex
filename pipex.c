/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoufid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 21:47:42 by mmoufid           #+#    #+#             */
/*   Updated: 2022/12/25 15:26:20 by mmoufid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	checkid(int id)
{
	if (id == -1)
		return (perror("error !!"));
}

static void	reduclines(int a, int b, int c, int d)
{
	close(a);
	close(b);
	waitpid(c, NULL, 0);
	waitpid(d, NULL, 0);
}

static void	pipex(char **env, char **commands, char **av, int fds[2])
{
	int	fd[2];
	int	id[2];

	if (pipe(fd) == -1)
		return (perror("error !!!"));
	id[0] = fork();
	checkid(id[0]);
	if (id[0] == 0)
	{
		child1requisite(fd, fds[0]);
		child1(env, commands[0], ft_split(av[2], ' '));
	}
	else
	{
		id[1] = fork();
		checkid(id[1]);
		if (id[1] == 0)
		{
			child2requisite(fd, fds[1]);
			child2(env, commands[1], ft_split(av[3], ' '));
		}
	}
	reduclines(fd[0], fd[1], id[0], id[1]);
}

static void	sentargstopipex(char **env, char **av, int fd1, int fd2)
{
	char	**commands;
	int		fds[2];
	char	**checkenv;

	fds[0] = fd1;
	fds[1] = fd2;
	checkenv = getpaths(env);
	if (checkenv == NULL)
	{	
		perror("there is no path");
		exit(-1);
	}
	commands = getcommands(av[2], av[3]);
	pipex(env, commands, av, fds);
}

int	main(int ac, char **av, char **env)
{
	int	fd1;
	int	fd2;

	fd1 = open(av[1], O_RDWR, 0644);
	fd2 = open(av[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (ac != 5 || fd1 < 0 || fd2 < 0)
		return (perror("some thing is wrong"), 0);
	if (access(av[2], F_OK | X_OK) == 0)
		av[2] = ft_memchr(av[2], '/', ft_strlen(av[2]));
	if (access(av[3], F_OK | X_OK) == 0)
		av[3] = ft_memchr(av[3], '/', ft_strlen(av[3]));
	sentargstopipex(env, av, fd1, fd2);
	return (0);
}
