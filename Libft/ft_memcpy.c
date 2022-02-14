/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijmari <ijmari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 11:07:03 by ijmari            #+#    #+#             */
/*   Updated: 2021/11/04 09:22:51 by ijmari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned int	i;
	int				j;
	char			*d;
	char			*s;

	i = 0;
	j = 0;
	d = (char *) dst;
	s = (char *) src;
	if (!s && !d)
		return (0);
	while (i < n)
		d[j++] = s[i++];
	return (d);
}
