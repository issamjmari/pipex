#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line/get_next_line.h"
#include "Libft/libft.h"

char	*get_command (char **av, char **env)
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
	arg = ft_split(av[2], ' ');
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
	char    *v[] = {"ls", "-l", "-a", NULL};
	int i = 0;

	fd = open (av[1], O_RDWR);
	char **u = ft_split(av[2], ' ');
	dup2(fd, 0);
	if (execve(get_command(av, env), ft_split(av[2], ' '), NULL) == -1)
		dprintf(2, "Error\n");
}
