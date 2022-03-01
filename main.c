/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijmari <ijmari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 11:07:04 by ijmari            #+#    #+#             */
/*   Updated: 2022/03/01 11:23:24 by ijmari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line/get_next_line.h"
#include "pipex.h"

void	ft_free(char **ptr1)
{
	int	i;
	int	count;

	i = 0;
	while (ptr1[i])
		free(ptr1[i++]);
	free(ptr1);
}

char	*get_command(char **av, char **env, int count)
{
	int		i;
	int		j;
	char	**paths;
	char	**arg;
	char	*temp;

	i = 0;
	j = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			paths = ft_split(ft_strnstr(env[i], "/", 6), ':');
		i++;
	}
	if (count == 0)
		arg = ft_split(av[2], ' ');
	if (count == 1)
		arg = ft_split(av[3], ' ');
	temp = path_valid(paths, arg, i, j);
	if (temp)
		return (temp);
	ft_free(paths);
	ft_free(arg);
	return (0);
}

void	second_f(char *path2, int fd_f[2], char **av, char **env)
{
	int	fd4;

	fd4 = open (av[4], O_RDWR | O_TRUNC | O_CREAT, 0777);
	if (fd4 == -1)
	{
		perror("");
		exit(1);
	}
	path2 = get_command(av, env, 1);
	if (!path2)
		error2(av);
	close(fd_f[1]);
	dup2(fd_f[0], 0);
	close(fd_f[0]);
	dup2(fd4, 1);
	close(fd4);
	if (execve(path2, ft_split(av[3], ' '), env) == -1)
		exit(1);
}

void	first_f(char *path, int fd_f[2], char **av, char **env)
{
	int	fd;

	fd = open (av[1], O_RDONLY);
	if (fd == -1)
	{
		perror("");
		exit(1);
	}
	path = get_command(av, env, 0);
	if (!path)
		error1(av);
	dup2(fd, 0);
	close(fd);
	close (fd_f[0]);
	dup2(fd_f[1], 1);
	close(fd_f[1]);
	if (execve(path, ft_split(av[2], ' '), env) == -1)
		exit(1);
}

int	main(int ac, char **av, char **env)
{
	int		id;
	int		id1;
	int		fd_f[2];
	char	*path;
	char	*path2;

	if (ac != 5)
	{
		write(2, "Error in arguments\n", 19);
		exit(1);
	}
	pipe(fd_f);
	id = fork();
	if (id == 0)
		first_f(path, fd_f, av, env);
	id1 = fork();
	if (id1 == 0)
		second_f(path2, fd_f, av, env);
	close(fd_f[0]);
	close(fd_f[1]);
	waitpid(id, NULL, 0);
	waitpid(id1, NULL, 0);
}
