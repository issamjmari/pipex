/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijmari <ijmari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 11:03:26 by ijmari            #+#    #+#             */
/*   Updated: 2022/02/28 18:12:36 by ijmari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error1(char **av)
{
	char	**all_lines;

	if (!ft_strncmp(av[2], "", 1))
	{
		write(2, "permission denied:", 18);
		write(2, "\n", 1);
		return ;
	}
	write(2, "command not found: ", 20);
	all_lines = ft_split(av[2], ' ');
	write(2, all_lines[0], ft_strlen(all_lines[0]));
	ft_free (all_lines);
	write(2, "\n", 1);
}

void	error2(char **av)
{
	char	**all_lines;

	if (!ft_strncmp(av[3], "", 1))
	{
		write(2, "permission denied:", 18);
		write(2, "\n", 1);
		return ;
	}
	write(2, "command not found: ", 20);
	all_lines = ft_split(av[3], ' ');
	write(2, all_lines[0], ft_strlen(all_lines[0]));
	ft_free(all_lines);
	write(2, "\n", 1);
}

char	*path_valid(char **paths, char **arg, int i, int j)
{
	char	*cpy;

	if(access(arg[0], F_OK) == 0)
			return (arg[0]);
	while (paths[j])
	{
		paths[j] = ft_strjoin(paths[j], "/");
		paths[j] = ft_strjoin(paths[j], arg[0]);
		if (access(paths[j], F_OK) == 0)
		{
			ft_free(arg);
			cpy = ft_substr(paths[j], 0, ft_strlen(paths[j]));
			ft_free(paths);
			return (cpy);
		}
		j++;
	}
	return (0);
}
