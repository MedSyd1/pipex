/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoufid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 21:59:55 by mmoufid           #+#    #+#             */
/*   Updated: 2022/12/25 15:00:27 by mmoufid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <errno.h>
# include <string.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <sys/wait.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

void	execute(char **paths, char **env, char *cmd, char **args);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *str);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*getcmd(char *arg);
int		ft_strchr(const char *hay, int c);
char	*getcmdoptions(char *arg);
int		checkminus(char *str);
char	*ft_strdup(const char *s1);
char	*updateargs(char *str);
char	**getpaths(char **env);
void	child2(char **env, char *command, char **arg2);
void	child1(char **env, char *command, char **arg1);
void	child1requisite(int fds[2], int fd);
void	child2requisite(int fds[2], int fd);
char	**getcommands(char *cmd1, char *cmd2);
int		checkcmd(char *cmd);
int		checkcmd(char *cmd);
int		check(char *cmd);
char	*ft_memchr(char *s, int c, size_t n);

#endif
