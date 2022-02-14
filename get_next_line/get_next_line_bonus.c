/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijmari <ijmari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 15:47:01 by ijmari            #+#    #+#             */
/*   Updated: 2021/11/19 17:51:55 by ijmari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	there_isn(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_get_tilln(const char *stock)
{
	int	i;

	i = 0;
	if (!stock[0])
		return (NULL);
	while (stock[i] && stock[i] != '\n')
		i++;
	return (ft_substr(stock, 0, i + 1));
}

char	*ft_remain(char *stock)
{
	int	i;

	i = 0;
	if (!stock)
		return (NULL);
	while (stock[i])
	{
		if (stock[i] == '\n')
			return (ft_substr(stock, i + 1, ft_strlen(stock)));
		i++;
	}
	return (0);
}

char	*ft_form(int fd, char *stock)
{
	char	*temp;
	int		rd;

	temp = malloc (BUFFER_SIZE + 1);
	rd = 1;
	while (rd != 0 && !there_isn(stock))
	{
		rd = read (fd, temp, BUFFER_SIZE);
		if (rd == -1)
		{
			free (temp);
			return (NULL);
		}
		temp[rd] = '\0';
		stock = ft_strjoin(stock, temp);
	}
	free (temp);
	return (stock);
}

char	*get_next_line(int fd)
{
	char		*ret;
	static char	*stock[FD_MAX];
	char		*old_value;

	if (fd < 0 || fd >= FD_MAX || BUFFER_SIZE < 0)
		return (NULL);
	stock[fd] = ft_form(fd, stock[fd]);
	if (!stock[fd])
		return (NULL);
	ret = ft_get_tilln(stock[fd]);
	old_value = stock[fd];
	stock[fd] = ft_remain(stock[fd]);
	free(old_value);
	return (ret);
}
