/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijmari <ijmari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 09:37:12 by ijmari            #+#    #+#             */
/*   Updated: 2021/11/07 10:48:05 by ijmari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	size;

	size = 0;
	if (c == 0)
		return ((char *)s + ft_strlen(s));
	while (s[size])
		size++;
	while (size >= 0)
	{
		if (s[size] == (unsigned char) c)
			return ((char *)&s[size]);
		size--;
	}
	return (0);
}
