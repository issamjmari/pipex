/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijmari <ijmari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 10:18:19 by ijmari            #+#    #+#             */
/*   Updated: 2021/11/11 17:20:12 by ijmari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*are_overlapping(char *d1, char *s1, int len2)
{
	len2--;
	while (len2 >= 0)
	{
		d1[len2] = s1[len2];
		len2--;
	}
	return (d1);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*d1;
	char	*s1;
	int		len2;
	int		lap;

	d1 = (char *) dst;
	s1 = (char *) src;
	len2 = (int) len;
	lap = 0;
	if (!d1 && !s1)
		return (0);
	if (d1 > s1)
	{
		d1 = are_overlapping(d1, s1, len2);
		return (d1);
	}
	else
	{
		d1 = ft_memcpy(d1, s1, len);
		return (d1);
	}
	return (0);
}
