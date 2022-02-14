/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijmari <ijmari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 09:23:58 by ijmari            #+#    #+#             */
/*   Updated: 2021/11/10 11:13:03 by ijmari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_word(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		while (s[i] && s[i] != c)
			i++;
		count++;
		while (s[i] && s[i] == c)
			i++;
	}
	return (count);
}

static char	*ft_stock(char const *s, char c)
{
	char	*temp;
	int		i;
	int		k;
	int		j;

	i = 0;
	k = 0;
	j = 0;
	while (s[i] && s[i] != c)
		i++;
	temp = (char *) malloc ((i + 1) * sizeof(char));
	if (!temp)
		return (NULL);
	while (k < i)
		temp[k++] = s[j++];
	temp[k] = '\0';
	return (temp);
}

static int	nextword(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

char	**ft_handle(int word, char const *s, char **stock, int c)
{
	int	i;
	int	j;

	i = 0;
	while (i < word)
	{
		j = 0;
		while (s[j] == c)
			j++;
		s += j;
		stock[i] = ft_stock(s, c);
		if (!stock[i])
		{
			while (--i)
				free(stock[i]);
			free(stock);
			return (NULL);
		}
		s += nextword(s, c);
		i++;
	}
	stock[i] = 0;
	return (stock);
}

char	**ft_split(char const *s, char c)
{
	int		word;
	char	**stock;

	if (!s)
		return (NULL);
	word = ft_count_word(s, c);
	stock = (char **) malloc ((word + 1) * sizeof(char *));
	if (!stock)
		return (NULL);
	return (ft_handle(word, s, stock, c));
}
