#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line/get_next_line.h"
#include "Libft/libft.h"

char	*get_command (char **av, char **env, int count)
{
	int i = 0;
	int j = 0;
	char **paths;
	char **arg;
	while (env[i])
	{
		if (strncmp(env[i],"PATH=",5) == 0)
			paths = ft_split(strnstr(env[i], "/", 6), ':');
		i++;
	}
	if (count == 0)
		arg = ft_split(av[2], ' ');
	if (count == 1)
		arg = ft_split(av[3], ' ');
	while (paths[j])
	{
		paths[j] = ft_strjoin(paths[j], "/");
		paths[j] = ft_strjoin(paths[j], arg[0]);
		if (access(paths[j], F_OK) == 0)
			return (paths[j]);
		j++;
	}
	return (0);
}
int main(int ac, char **av, char **env)
{
	int fd;
	int	i;
	int	fd_f[2];
	int id;
	int id1;

	fd = open (av[1], O_RDWR);
	dup2(fd, 0);
	close(fd);
	pipe(fd_f);
	id = fork();
	if (id == 0)
	{
		dup2(fd_f[1], STDOUT_FILENO);
		close(fd_f[0]);
		close(fd_f[1]);
		if (execve(get_command(av, env, 0), ft_split(av[2], ' '), NULL) == -1)
			write(1, "Error\n", 6);
	}
	id1 = fork();
	if (id1 == 0)
	{
		dup2(fd_f[0], STDIN_FILENO);
		close(fd_f[0]);
		close(fd_f[1]);
		int fd4 = open(av[4], O_RDWR | O_CREAT, 0777);
		dup2(fd4, STDOUT_FILENO);
		if (execve(get_command(av, env, 1), ft_split(av[3], ' '), NULL) == -1)
			write(1, "Error\n", 6);
	}
	close(fd_f[0]);
	close(fd_f[1]);
	waitpid(id, NULL, 0);
	waitpid(id1, NULL, 0);
}