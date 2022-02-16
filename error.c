#include "pipex.h"


void error1 (char **av)
{
		if(!ft_strncmp(av[2], "", 1))
		{
			write(2, "permission denied:", 18);
			write(2, "\n", 1);
			exit(1);
		}
		write(2, "command not found: ", 20);
		write(2, ft_split(av[2], ' ')[0], ft_strlen(ft_split(av[2], ' ')[0]));
		write(2, "\n", 1);
		exit(1);
}

void error2 (char **av)
{
		if(!ft_strncmp(av[3], "", 1))
		{
			write(2, "permission denied:", 18);
			write(2, "\n", 1);
			exit(1);
		}
		write(2, "command not found: ", 20);
		write(2, ft_split(av[3], ' ')[0], ft_strlen(ft_split(av[2], ' ')[0]));
		write(2, "\n", 1);
		exit(1);
}