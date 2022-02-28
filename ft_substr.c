/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijmari <ijmari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 09:38:37 by ijmari            #+#    #+#             */
/*   Updated: 2022/02/19 11:23:15 by ijmari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*temp;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		len = 0;
	else if (ft_strlen(s) < len)
		len = ft_strlen(s) - start;
	temp = (char *)malloc(len + 1);
	if (!temp)
		return (0);
	while (s[start] && i < len)
		temp[i++] = s[start++];
	temp[i] = '\0';
	return (temp);
}
