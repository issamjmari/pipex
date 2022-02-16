#include <stdio.h>$
#include <string.h>$
#include <unistd.h>$
#include <fcntl.h>$
#include "get_next_line/get_next_line.h"$
#include "pipex.h"$
void	ft_free(char **ptr1, char **ptr2)$
{$
	int i;$
	int j;$
$
	j = 0;$
	i = 0;$
	while (ptr1[i])$
		i++;$
	while(ptr2[j])$
		j++;$
	while(ptr1[--i])$
		free(ptr1[i]);$
	free(ptr1);$
	while(ptr2[--j])$
		free(ptr1[j]);$
	free(ptr2);$
}$
char	*get_command (char **av, char **env, int count)$
{$
	int i = 0;$
	int j = 0;$
	char **paths;$
	char **arg;$
	while (env[i])$
	{$
		if (ft_strncmp(env[i],"PATH=",5) == 0)$
			paths = ft_split(ft_strnstr(env[i], "/", 6), ':');$
		i++;$
	}$
	if (count == 0)$
		arg = ft_split(av[2], ' ');$
	if (count == 1)$
		arg = ft_split(av[3], ' ');$
	while (paths[j])$
	{$
		paths[j] = ft_strjoin(paths[j], "/");$
		paths[j] = ft_strjoin(paths[j], arg[0]);$
		if (access(paths[j], F_OK) == 0)$
			return (paths[j]);$
		j++;$
	}$
	return (0);$
}$
$
void	second_f(char *path, int fd_f[2], char **av, char **env)$
{$
	int	fd4;$
	int	id1;$
$
	if (id1 == 0)$
	{$
		dup2(fd_f[0], STDIN_FILENO);$
		close(fd_f[0]);$
		close(fd_f[1]);$
		fd4 = open(av[4], O_RDWR | O_CREAT | O_TRUNC, 0777);$
		dup2(fd4, STDOUT_FILENO);$
		execve(path, ft_split(av[3], ' '), NULL);$
	}$
	// waitpid(id1, NULL, 0);$
}$
void	first_f(char *path, int fd_f[2], char **av, char **env)$
{$
	int	id;$
$
	id = fork();$
	if (id == 0)$
	{$
		dup2(fd_f[1], STDOUT_FILENO);$
		close(fd_f[0]);$
		close(fd_f[1]);$
		execve(path, ft_split(av[2], ' '), NULL);$
	}$
	waitpid(id, NULL, 0);$
}$
int main(int ac, char **av, char **env)$
{$
	int		fd;$
	int		i;$
	int		fd_f[2];$
	char	*path;$
	char	*path2;$
$
	fd = open (av[1], O_RDWR);$
	if(fd == -1)$
	{$
		printf("no such file or directory: %s\n", av[1]);$
		exit(1);$
	}$
	path = get_command(av, env, 0);$
	if(!path)$
		error1(av);$
	dup2(fd, 0);$
	close(fd);$
	pipe(fd_f);$
	first_f(path ,fd_f, av, env);$
	path2 = get_command(av, env, 1);$
	if(!path2)$
		error2(av);$
	second_f(path2, fd_f, av, env);$
	write(2, "OPOO\n", 5);$
	close(fd_f[0]);$
	close(fd_f[1]);$
	while(1);$
}