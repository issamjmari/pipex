/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijmari <ijmari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 09:03:40 by ijmari            #+#    #+#             */
/*   Updated: 2021/11/10 11:19:07 by ijmari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_stock(char *s1, int stock, int last, char *temp)
{
	int	i;

	i = 0;
	while (s1[stock] && i < last)
		temp[i++] = s1[stock++];
	return (temp);
}

int	ft_counti(char const *s1, char const *set)
{
	int	i;

	i = 0;
	while (is_set(s1[i], set))
		i++;
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*temp;
	int		len;
	int		stock;
	int		last;
	int		i;

	if (!s1)
		return (NULL);
	if (!set)
		return ((char *)s1);
	len = ft_strlen(s1);
	last = len;
	i = ft_counti(s1, set);
	stock = i;
	if (i != len)
		while (is_set(s1[--len], set))
			i++;
	last = last - i;
	temp = (char *) malloc (last + 1);
	i = 0;
	if (!temp)
		return (0);
	temp = ft_stock((char *)s1, stock, last, temp);
	temp[last] = '\0';
	return (temp);
}
